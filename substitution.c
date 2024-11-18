#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
    }
    else {
        if (strlen(argv[2]) != 26) {
            printf("Key must contain 26 characters.\n");
        }
    }
    
}
