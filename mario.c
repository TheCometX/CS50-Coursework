#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num = get_int("Height: \n");
    for (int num; num > 0; num--)
    {
        printf("%d", num);
    }
}
