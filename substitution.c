#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
    }
    else {
        if (len != 26) {
            printf("Key must contain 26 characters.\n");
        }
    }
    char letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string text = get_string("plaintext: ");
    for (int y = 0; y < 25; y++) {
        char letter = argv[y];
        if (isalpha(letter) && isdigit(letter) != false) {
            for (int x = 0; x < 25; x++) {
                
            }
        }
    }
}
