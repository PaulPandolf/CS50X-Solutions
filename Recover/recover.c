#include <stdio.h>
#include <stdlib.h>

#include "typedef.h"

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./recover file\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int num = 0;

    char filename[50];
    int file_number = -1;
    FILE *img = NULL;

    // Repeat until end of infile
    while (fread(buffer, 512, 1, inptr))
    {
        // if start of new jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
        buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            // if first file
            if (file_number == -1) {
                file_number = 0;
                sprintf(filename, "%03i.jpg", file_number);
                file_number++;
                img = fopen(filename, "w" );
                fwrite(buffer, 512, 1, img);

            // if not first file
            } else if (file_number > 0) {
                fclose(img);
                sprintf(filename, "%03i.jpg", file_number);
                file_number++;
                img = fopen(filename, "w" );
                fwrite(buffer, 512, 1, img);
            }

            // if found JPEG already
        } else if (file_number >= 0) {
            fwrite(buffer, 512, 1, img);
        }
    }
    fclose(img);
    printf("end of file\n");
    fclose(inptr);
}