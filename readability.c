#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main() {
    string text = get_string("Text: ");
    int len = strlen(text);
    int words = 1;
    int letters = 0;
    for (int y = 0; y < len; y++) {
        char letter = text[y];
        if (letter != '.' || letter != '?' || letter != '!' || letter != ''' || letter != '"' || letter != ',' || letter != '(' || letter != ')' || letter != '[' || letter != '/' || letter != '*' || letter != ':' || letter != '-' || letter != '_' || letter != ';') {
            letters += 1;
        }
        else {
            if (letter == '.') {
                sentences += 1;
            }
        }
    }
    int grade = 0.0588 * L - 0.296 * S - 15.8
    printf("%i\n", letters);
    printf("%i\n", words);
}
