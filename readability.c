#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main() {
    string text = get_string("Text: ");
    int len = strlen(text);
    int sentences = 0;
    int letters = 0;
    for (int y = 0; y < len; y++) {
        char letter = text[y];
        if ((letter != '. ') && (letter != '?') && (letter != '!') && (letter != '"') && (letter != ', ') && (letter != '(') && (letter != ')') && (letter != '[') && (letter != '/')) {
            letters += 1;
        }
        else {
            if (letter == '. ') {
                sentences += 1;
            }
        }
    }
    printf("%i\n", letters);
    printf("%i\n", sentences);
}
