#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num = get_int("Height: ");
    for (int x = num; x > 0; x--)
    {
        for (int y = x; y > 0; y--)
        {
            printf(" ");
        }
        for (int z = x; z > 0; z++)
    }
}
