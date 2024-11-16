#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main() {
    string text = get_string("Text: ");
    int len = strlen(text);
    int words = 0;
    int letters = 0;
    for (int y = 0; y < len; y++) {
        char letter = text[y];
        if (letter != ' ') {
            letters += 1;
        }
        else {
            words += 1;
        }
    }
    printf("%i\n", letters);
    printf("%i\n", words);
}
