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
        string letter = text[y];
        if (strcmp(letter, " ")) {

        }
    }
}
