#include <cs50.h>
#include <stdio.h>

int main()
{
    int x = get_int("What is x? ");
    int y = get_int("What is y? ");

    if (x < y)
    {
        printf("Y is bigger.\n");
    }
    else
    {
        printf("X is bigger.\n");
    }
}
