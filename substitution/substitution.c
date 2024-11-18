#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
    }
    else {
        if (strlen(argv[1]) != 26) {
            printf("Key must contain 26 characters.\n");
        }
        else {
            char letters[26]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            string text = get_string("plaintext: ");
            for (int x = 0; x < strlen(text); x++) {
                char letter = text[x];
                int times = 1;
                if (isalpha(letter)) {
                    for (int y = 0; y < 26; y++) {
                        if (letter == letters[y]) {
                            char letter2 = argv[1][y];
                            if (times == 1) {
                                printf("%c", toupper(letter2));
                                times += 1;
                            }
                            else {
                                printf("%c", letter2);
                            }
                        }
                    }
                }
                else {
                    printf("%c", letter);
                }
            }
            printf("\n");
        }
    }
}
