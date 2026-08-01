#include <SDL3/SDL.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>
#include <cstddef>
#include <cstdio>
#include <imgui.h>
#include <trse/SaveInfo.hpp>
#include <trse/gui/Core.hpp>
#include <trse/gui/File.hpp>
#include <trse/gui/Render.hpp>
#include <trse/gui/Style.hpp>
#include <trse/saved/Campsites.hpp>

using namespace TRSE;

static SaveInfo saveInfo;

int main(void)
{
    char path[512] = "No file";
    int err = GUI::Init();
    if (err < 0)
    {
        printf("GUI::Init failed, err = %d\n", err);
        return err;
    }

    while (1)
    {
        if (GUI::StartFrame())
        {
            printf("Quitting\n");
            break;
        }

        {

            if (saveInfo.m_infoSize)
            {
                ImGui::Begin(path);

                if (ImGui::Button("Export File"))
                {
                    GUI::FileSavePath(path, sizeof(path));
                    FILE *file = fopen(path, "wb");
                    if (file != nullptr)
                    {
                        unsigned char *dst = new unsigned char[sizeof(saveInfo)];
                        unsigned int size = sizeof(saveInfo);
                        saveInfo.PackSaveInfo(dst, &size);
                        fwrite(dst, size, 1, file);
                        fclose(file);
                        delete[] dst;
                    }
                }
                if (ImGui::Button("Set Backward Compatible"))
                {
                    saveInfo.SetBackwardCompatible();
                }
                GUI::Render(saveInfo, "SaveInfo");
            }
            else
            {
                ImGui::Begin("no file");
                if (ImGui::Button("Import File"))
                {
                    GUI::FileBrowsePath(path, sizeof(path));
                    FILE *file = fopen(path, "rb");
                    if (file != nullptr)
                    {
                        fseek(file, 0, SEEK_END);
                        size_t file_size = ftell(file);
                        rewind(file);
                        unsigned char *compressed = new unsigned char[file_size];
                        fread(compressed, file_size, 1, file);
                        fclose(file);
                        int err = saveInfo.ExtractSaveInfo(compressed, file_size);
                        if (err)
                        {
                            printf("ExtractSaveInfo failed, err = %d\n", err);
                        }
                        delete[] compressed;
                    }
                }
            }
            ImGui::End();
        }
        GUI::EndFrame();
    }

    GUI::Destroy();

    return 0;
}
