#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    int len = strlen(argv[2]);
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
