#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main() {
    long int cardNum = get_long("Number: ");
    int length = 0;
    int result = 0;

    for (long int x = 1; x <= cardNum; x *= 10)
    {
        length += 1;
        long int div = cardNum / x;
        int digit = div % 10;
        if (length % 2 == 0)
        {
            int digit2 = digit * 2;
            result += digit2 % 10;
            result += digit2 / 10;
        }
        else
        {
            result += digit;
        }
    }
    if (result % 10 == 0)
    {
        if (length == 13)
        {
            if (cardNum / pow(10, 12) == 4)
            {
                printf("VISA\n");
            }
        }
        else if (length == 15)
        {
            int first = cardNum / pow(10, 13) == 3;
            if (2first == 34 || 2first == 37)
            {
                printf("AMEX\n");
            }
        }
        else if (length == 16)
        {
            int d = cardNum / pow(10, 14);
            if (d <= 55 && d >= 51)
            {
                printf("MASTERCARD\n");
            }
            else if (d \ 10 == 4)
            {
                printf("VISA\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
