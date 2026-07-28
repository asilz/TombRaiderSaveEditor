#include <cinttypes>
#include <imgui.h>
#include <trse/SaveInfo.hpp>
#include <trse/saved/ActionGraph.hpp>
#include <trse/saved/Campsites.hpp>
#include <zlib.h>

namespace TRSE
{

int SaveInfo::ExtractSaveInfo(char *input, unsigned int input_size)
{
    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    infstream.avail_in = input_size;                              // size of input
    infstream.next_in = (Bytef *)input;                           // input char array
    infstream.avail_out = offsetof(SaveInfo, m_firstDeleteBlock); // size of output
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

int SaveInfo::Render(const char *label)
{
    ImGui::Text(label);
    int i = 0;
    for (uint8_t *info = m_infoStart; info < m_infoStart + m_infoSize;
         info = info + (*(reinterpret_cast<uint32_t *>(info)) >> 6 & 0x3fffffc))
    {
        int ret;
        ImGui::PushID(i++);
        switch (*info)
        {
        case SavedCampsites::SAVED_ID:
            ret = reinterpret_cast<SavedCampsites *>(info)->Render("SavedCampsites");
            break;

        default:
            ret = 0;
            break;
        }
        ImGui::PopID();
    }

    return 0;
}
}; // namespace TRSE