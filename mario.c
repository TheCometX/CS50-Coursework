#include <cs50.h>
#include <stdio.h>

void spaces(int h);
void stair(int x);

int main(void)
{
    int height = get_int("What's the height? ");
    int num = height;

    for (int x = 1; x <= height; x++)
    {
        spaces(height);
        stair(x);
        printf("\n");
        num -= 1;
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

void spaces(int h)
{
    int times = h - 1;
    for (int z = times; z > 0; z--)
        {
            printf(" ");
        }
    times -= 1;
}
