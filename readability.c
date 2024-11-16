#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main() {
    string text = get_string("Text: ");
    int len = strlen(text);
    float sentences = 0;
    float letters = 0;
    float words = 1;
    for (int y = 0; y < len; y++) {
        if (words == 100) {
            break;
        }
        char letter = text[y];
        if (isalpha(letter) != 0) {
            letters += 1;
        }
        else {
            if (letter == ' '){
                words += 1;
            }
            else {
                if (letter == '.' || letter == '?' || letter == '!') {
                    sentences += 1;
                }
            }
        }
    }
    int result = 0.0588 * ((letters / words) * 100) - 0.296 * ((sentences / words) * 100) - 15.8;
    printf("%.0f\n", letters);
    printf("%.0f\n", sentences);
    printf("%.0f\n", words);
    printf("%i\n", result);
}

