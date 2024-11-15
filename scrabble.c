#include <stdio.h>
#include <string.h>

int len(char word);

int main() {
    char word1[] = "Vinicius";
    char word2[] = "Felipe";
    int x = 0;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int total1;
    int total2;
    int y = 0;
    while (y < len1) {
        char digit = toupper(word1[y]);
        if (digit == 'A' || digit == 'E' || digit == 'I' || digit == 'L' || digit == 'N' || digit == 'O' || digit == 'R' || digit == 'S' || digit == 'T' || digit == 'U') {
            total1 += 1;
        }
        else {
            if (digit == 'D' || digit == 'G') {
                total1 += 2;
            }
            else {
                if (digit == 'B' || digit == 'C' || digit == 'M' || digit == 'P') {
                total1 += 3;
                }
                else {
                    if (digit == 'F' || digit == 'H' || digit == 'V' || digit == 'W' || digit == 'Y') {
                    total1 += 4;
                    }
                    else {
                        if (digit == 'K') {
                        total1 += 5;
                        }
                        else {
                            if (digit == 'J' || digit == 'X') {
                            total1 += 8;
                            }
                            else {
                                if (digit == 'Q' || digit == 'Z') {
                                total1 += 10;
                                }
                            }
                        }
                    }
                }
            }
        }
        y++;
    }
}
