#include <cinttypes>
#include <trse/SaveInfo.hpp>
#include <trse/saved/ActionGraph.hpp>
#include <zlib.h>

namespace TRSE
{

int SaveInfo::ExtractSaveInfo(char *input, unsigned int input_size)
{
    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    infstream.avail_in = input_size;                                                                 // size of input
    infstream.next_in = (Bytef *)input;                                                              // input char array
    infstream.avail_out = offsetof(SaveInfo, m_firstDeleteBlock) + sizeof(this->m_firstDeleteBlock); // size of output
    infstream.next_out = (Bytef *)this; // This is undefined behaviour, but I think this is what the game does

    int ret = inflateInit2(&infstream, 0xf); // 0xf because this is what rise does
    if (ret)
    {
        return ret;
    }

    ret = inflate(&infstream, Z_FINISH); // defined to 4 in Rise. Probably Z_FINISH
    if (ret != Z_STREAM_END)
    {
        return ret;
    }

    return 0;
}

int SaveInfo::Render(void)
{
    for (uint8_t *info = m_infoStart; info < m_infoStart + m_infoSize;
         info = info + (*(reinterpret_cast<uint32_t *>(info)) >> 6 & 0x3fffffc))
    {
        int err;
        switch (*info)
        {
        case SavedActionGraph::SAVED_ID:
            err = reinterpret_cast<SavedActionGraph *>(info)->Render("SavedActionGraph");
            break;

        default:
            err = 0;
            break;
        }
        if (err)
        {
            return err;
        }
    }

    return 0;
}
}; // namespace TRSE