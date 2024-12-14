#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main()
{
    long int cardNum = get_long("Number: ");
    int length = 0;
    int result = 0;

    // Luhn's Algorithm
    for (long int x = 1; x <= cardNum; x *= 10)
    {
        length += 1;
        long int div = cardNum / x;
        int digit = div % 10;
        // choose the digits to be multiplied (start in the second)
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
    // check if the luhn's algorithm result is valid
    if (result % 10 == 0)
    {
        // check for VISA with 13 digits
        if (length == 13)
        {
            // get the 2 first digits
            int first = cardNum / pow(10, 12);
            if (first == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // check for AMEX
        else if (length == 15)
        {
            // get the two first digits
            int first = cardNum / pow(10, 13);
            if (first == 34 || first == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // check for MASTERCARD and VISA with 16 digits
        else if (length == 16)
        {
            // get the 2 first digits
            int first = cardNum / pow(10, 14);
            if (first <= 55 && first >= 51)
            {
                printf("MASTERCARD\n");
            }
            // check if the first digit is 4 (VISA)
            else if (first / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // if Luhn's algorithm result is invalid
    else
    {
        printf("INVALID\n");
    }
}
