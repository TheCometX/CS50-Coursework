// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    int16_t b;

    for (int x = 0; x < HEADER_SIZE; x += 2)
    {
        fread(&b, sizeof(b), 1, input);
        fwrite(&b, sizeof(b), 1, output);
    }

    while (fread(&b, sizeof(b), 1, input) != 0)
    {
        b *= factor;
        fwrite(&b, sizeof(b), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
