#include <cstdio>
#include <trse/SaveInfo.hpp>

using namespace TRSE;

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

    if (err)
    {
        printf("Could not extract save, err = %d\n", err);
    }

    return 0;
}