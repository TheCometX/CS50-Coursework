#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    uint8_t buffer[512];
    char* filename = malloc(sizeof(char) * 7);
    int files = 0;
    int writing = 0;
    FILE* img;

    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (files == 0)
            {
                sprintf(filename, "%03i.jpg", files);
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                files++;
                writing = 1;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", files);
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                files++;
            }
        }
        else if (writing == 1)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(img);
    fclose(card);
    free(filename);
    writing = 0;
}
