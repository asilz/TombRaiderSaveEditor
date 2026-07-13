#include <cstdio>
#include <zlib.h>

int main(void)
{

    FILE *file = fopen("../save/save1.dat", "rb");
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);
    char *compressed = new char[file_size];
    fread(compressed, file_size, 1, file);
    char *decompressed = new char[0xffffffff];

    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    // setup "b" as the input and "c" as the compressed output
    infstream.avail_in = file_size;             // size of input
    infstream.next_in = (Bytef *)compressed;    // input char array
    infstream.avail_out = (uInt)0xffffffff;     // size of output
    infstream.next_out = (Bytef *)decompressed; // output char array
    int ret = inflateInit2(&infstream, 0xf);    // 0xf because this is what rise does

    if (ret)
    {
        printf("Error inflateInit2, err = %d\n", ret);
        return 0;
    }

    ret = inflate(&infstream, Z_FINISH); // defined to 4 in Rise. Probably Z_FINISH
    if (ret == Z_STREAM_END)
    {
        printf("stream end\n");
        inflateEnd(&infstream);

        FILE *output_file = fopen("../save/save1_decompressed.dat", "wb");
        fwrite(decompressed, infstream.total_out, 1, output_file);
    }
}