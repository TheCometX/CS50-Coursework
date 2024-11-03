#include <cs50.h>
#include <stdio.h>

void spaces(int h);
void stair(int x);

int main(void)
{
    int height = get_int("What's the height? ");
    int times = height - 1;

    for (int x = 1; x <= height; x++)
    {
        spaces(times);
        stair(x);
        printf("\n");
        times -= 1;
    }
}

void stair(int x)
{
    for (int y = 1; y <= x; y++)
    {
        printf("#");
    }
    printf("  ");
    for (int y = 1; y <= x; y++)
    {
        printf("#");
    }
}

void spaces(int t)
{
    for (int z = t; z > 0; z--)
        {
            printf(" ");
        }
}
