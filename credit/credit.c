#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main() {
    long int cardNum = get_long("Number: ");
    int length = 0;
    int result = 0;

    for (long int x = 1; x <= cardNum; pow(x, 10))
    {
        length += 1;
        int digit = cardNum / x;
        if (length % 2 == 0)
        {
            digit *= 2;
            result += digit % 10;
            result += digit / 10;
        }
        else
        {
            result += digit
        }
    }

    if (length == 13)
    {

    }
    else if (length == 15)
    {

    }
    else if ()
}
