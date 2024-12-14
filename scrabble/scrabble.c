#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int points(string word);

int main() {
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // check if the words are the same (tie)
    if (points(word1) == points(word2)) {
        printf("Tie!\n");
    }
    // check which are greater
    else {
        if (points(word1) > points(word2)) {
            printf("Player 1 wins!\n");
        }
        else {
            printf("Player 2 wins!\n");
        }
    }
}

int points(string word) {
    int total = 0;
    int len = strlen(word);
    int y = 0;
    while (y < len) {
        char digit = toupper(word[y]);
        if (digit == 'A' || digit == 'E' || digit == 'I' || digit == 'L' || digit == 'N' || digit == 'O' || digit == 'R' || digit == 'S' || digit == 'T' || digit == 'U') {
            total += 1;
        }
        else {
            if (digit == 'D' || digit == 'G') {
                total += 2;
            }
            else {
                if (digit == 'B' || digit == 'C' || digit == 'M' || digit == 'P') {
                total += 3;
                }
                else {
                    if (digit == 'F' || digit == 'H' || digit == 'V' || digit == 'W' || digit == 'Y') {
                    total += 4;
                    }
                    else {
                        if (digit == 'K') {
                        total += 5;
                        }
                        else {
                            if (digit == 'J' || digit == 'X') {
                            total += 8;
                            }
                            else {
                                if (digit == 'Q' || digit == 'Z') {
                                total += 10;
                                }
                            }
                        }
                    }
                }
            }
        }
        y++;
    }
    return total;
}
