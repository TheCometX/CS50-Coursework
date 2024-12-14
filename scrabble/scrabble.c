#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// function used to find the points of the word
int points(string word);

int main() {
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // check if the words are the same (tie)
    if (points(word1) == points(word2)) {
        printf("Tie!\n");
    }
    else {
        // check if word 1 is greater
        if (points(word1) > points(word2)) {
            printf("Player 1 wins!\n");
        }
        // word 1 isn't greater
        else {
            printf("Player 2 wins!\n");
        }
    }
}

int points(string word) {
    // the total and length of string
    int total = 0;
    int len = strlen(word);
    int y = 0;
    // loop to check letter per letter
    while (y < len) {
        // index and upper case the letter
        char digit = toupper(word[y]);
        // check the letters with value 1
        if (digit == 'A' || digit == 'E' || digit == 'I' || digit == 'L' || digit == 'N' || digit == 'O' || digit == 'R' || digit == 'S' || digit == 'T' || digit == 'U') {
            total += 1;
        }
        else {
            // check the letters with value 2
            if (digit == 'D' || digit == 'G') {
                total += 2;
            }
            else {
                // check the letters with value 3
                if (digit == 'B' || digit == 'C' || digit == 'M' || digit == 'P') {
                total += 3;
                }
                else {
                    // check the letters with value 4
                    if (digit == 'F' || digit == 'H' || digit == 'V' || digit == 'W' || digit == 'Y') {
                    total += 4;
                    }
                    else {
                        // check the letters with value 5
                        if (digit == 'K') {
                        total += 5;
                        }
                        else {
                            // check the letters with value 8
                            if (digit == 'J' || digit == 'X') {
                            total += 8;
                            }
                            else {
                                // check the letters with value 10
                                if (digit == 'Q' || digit == 'Z') {
                                total += 10;
                                }
                            }
                        }
                    }
                }
            }
        }
        // inscrease the index number
        y++;
    }
    return total;
}
