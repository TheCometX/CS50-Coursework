#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    int len = strlen(argv[2]);
    char letter[26];
    for (int y = 0; y < len; y++) {
        char letter = (argv[2])[y];
        if (isalpha(letter)) {

        }
    }

    if (argc != 2) {
        printf("Usage: ./substitution key\n");
    }
    else {
        if (len != 26) {
            printf("Key must contain 26 characters.\n");
        }
    }
    string text = get_string("plaintext: ");

}
