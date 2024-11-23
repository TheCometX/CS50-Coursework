#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
 if (argc != 4)
 {
    printf("Usage: ./volume input.wav output.wav factor\n");
 }
 FILE *input = fopen(argv[1], "r");
 if (input == NULL)
 {
    printf("Could not open file.\n");
 }
 FILE *output = fopen(argv[2], "w");
 if (output == NULL)
 {
    printf("Could not open file.\n");
 }

}
