// TODO: Fix this mess

#define ZLIB_CONST
#ifndef Z_ARG /* function prototypes for stdarg */
#if defined(STDC) || defined(Z_HAVE_STDARG_H)
#define Z_ARG(args) args
#else
#define Z_ARG(args) ()
#endif
#endif

#include <cinttypes>
#include <cstdio>
#include <imgui.h>
#include <trse/SaveInfo.hpp>
#include <trse/saved/ActionGraph.hpp>
#include <trse/saved/Campsites.hpp>
#include <zlib.h>

namespace TRSE
{

static constexpr unsigned int SAVE_INFO_SIZE = 0x400000;

int SaveInfo::ExtractSaveInfo(const unsigned char *input, unsigned int input_size)
{
    printf("Zlib version: %s\n", ZLIB_VERSION);

    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    infstream.avail_in = input_size;      // size of input
    infstream.next_in = input;            // input char array
    infstream.avail_out = SAVE_INFO_SIZE; // size of output
    infstream.next_out =
        reinterpret_cast<Bytef *>(this); // This is undefined behaviour, but I think this is what the game does

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

int SaveInfo::PackSaveInfo(unsigned char *output, unsigned int *output_size)
{
    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    infstream.avail_in = SAVE_INFO_SIZE;
    infstream.next_in = reinterpret_cast<Bytef *>(this);
    infstream.avail_out = *output_size;
    infstream.next_out = output;

    int err = deflateInit(&infstream, Z_DEFAULT_COMPRESSION);
    if (err)
    {
        return err;
    }

    err = deflate(&infstream, Z_FINISH);

    deflateEnd(&infstream);
    *output_size = infstream.total_out;
    if (err != Z_STREAM_END)
    {
        return -5;
    }

    return 0;
}

int SaveInfo::Render(const char *label)
{
    ImGui::Text(label);
    int i = 0;
    // TODO: Figure out why newer binary seems to use 24 bits of info size for the actual size
    for (uint8_t *info = m_infoStart; info < m_infoStart + (m_infoSize & 0xffffff);
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