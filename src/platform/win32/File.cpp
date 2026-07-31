#include <Windows.h>
#include <cstdio>

namespace TRSE
{
namespace GUI
{

int FileBrowsePath(char *buf, size_t maxLength)
{
    OPENFILENAME open = {0};
    open.lStructSize = sizeof(OPENFILENAME);
    open.lpstrFilter = ".dat file\0*.dat\0";
    open.lpstrFile = buf;
    open.lpstrFile[0] = '\0';
    open.nMaxFile = maxLength;
    open.nFilterIndex = 1;
    open.lpstrTitle = "Select a .dat file\0";
    open.nMaxFileTitle = strlen(open.lpstrTitle);
    open.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
    return !GetOpenFileName(&open);
}
int FileSavePath(char *buf, size_t maxLength)
{
    OPENFILENAME open = {0};
    open.lStructSize = sizeof(OPENFILENAME);
    open.lpstrFilter = ".dat\0*.dat\0";
    open.lpstrFile = buf;
    open.lpstrFile[0] = '\0';
    open.nMaxFile = maxLength;
    open.nFilterIndex = 1;
    open.lpstrTitle = "Save a .dat file\0";
    open.nMaxFileTitle = strlen(open.lpstrTitle);
    open.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
    return !GetSaveFileName(&open);
}

}; // namespace GUI
}; // namespace TRSE