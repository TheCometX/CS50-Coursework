#include <cs50.h>
#include <stdio.h>

void stair(int x);

int main(void)
{
    int height = get_int("What's the height? ");

    for (int x = 1; x <= height; x++)
    {
        for (int z = height - 1; z > 0; z--)
        {
            printf(" ");
        }
        stair(x);
        printf("\n");
    }

}

void stair(int x)
{
    for (int y = 1; y <= x; y++)
    {
        printf("#");
    }
    printf(" ");
    for (int y = 1; y <= x; y++)
    {
        printf("#");
    }
}
