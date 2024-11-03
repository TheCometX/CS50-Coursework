#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num = get_int("Height: ");
    for (int x = num; x > 0; x--)
    {
        for (int y = num; y > 0; y--)
        {
            printf(" ");
        }
        printf("# #\n");
    }
}
