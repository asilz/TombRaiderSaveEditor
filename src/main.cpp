#include "imgui.h"
#include <SDL3/SDL.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>
#include <cstddef>
#include <cstdio>
#include <trse/SaveInfo.hpp>
#include <trse/gui/Core.hpp>
#include <trse/gui/Render.hpp>
#include <trse/gui/Style.hpp>
#include <trse/saved/Campsites.hpp>
using namespace TRSE;

/*

int main(void)
{

    FILE *file = fopen("../save/save1.dat", "rb");
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);
    char *compressed = new char[file_size];
    fread(compressed, file_size, 1, file);
    SaveInfo saveInfo;
    int err = saveInfo.ExtractSaveInfo(compressed, file_size);
    delete[] compressed;

    printf("offset = %lX\n", offsetof(SaveInfo, m_infoSize));

    SavedCampsites *campsites = saveInfo.GetBlock<SavedCampsites>();

    for (int i = 0; i < campsites->campsitesCount; ++i)
    {
        printf("campsite %d state = %d\n", i, campsites->campsiteData[i].m_state);
    }

    if (err)
    {
        printf("Could not extract save, err = %d\n", err);
    }

    return 0;
}
    */

#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

// Main code
int main(int, char **)
{
    FILE *file = fopen("../save/save1.dat", "rb");
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);
    char *compressed = new char[file_size];
    fread(compressed, file_size, 1, file);
    SaveInfo saveInfo;
    int err = saveInfo.ExtractSaveInfo(compressed, file_size);
    delete[] compressed;

    printf("offset = %lX\n", offsetof(SaveInfo, m_infoSize));
    printf("retro offset = %lX\n", offsetof(SaveInfo, m_retroSave));
    printf("info size = %d\n", saveInfo.m_infoSize);
    printf("retro size = %lX\n", sizeof(saveInfo.m_retroSave));

    FILE *out_file = fopen("../save/save1_old_decompressed.dat", "wb");
    fwrite(reinterpret_cast<void *>(&saveInfo), sizeof(saveInfo), 1, out_file);
    fclose(out_file);

    SavedCampsites *campsites = saveInfo.GetBlock<SavedCampsites>();

    for (int i = 0; i < campsites->campsitesCount; ++i)
    {
        printf("campsite %d state = %d\n", i, campsites->campsiteData[i].m_state);
    }

    if (err)
    {
        printf("Could not extract save, err = %d\n", err);
    }

    GUI::Init();

    while (1)
    {
        if (GUI::StartFrame())
        {
            break;
        }

        {

            ImGui::Begin("Hello, world!");
            GUI::Render(saveInfo, "SaveInfo");
            ImGui::End();
        }
        GUI::EndFrame();
    }

    return 0;
}
