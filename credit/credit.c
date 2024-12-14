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
        int digit = cardNum / x;
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

    printf("%i\n", length);
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
            if (cardNum / pow(10, 14) == 3)
            {
                int d = cardNum / pow(10, 13);
                if (d == 4 || d == 7)
                {
                    printf("AMEX\n");
                }
            }
        }
        else if (length == 16)
        {
            int d = cardNum / pow(10, 15);
            if (d == 5)
            {
                int d2 = cardNum / pow(10, 14);
                if (d2 <= 5 && d2 > 0)
                {
                    printf("MASTERCARD\n");
                }
            }
            else if (d == 4)
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
