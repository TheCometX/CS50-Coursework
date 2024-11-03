#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int height = get_int("What's the height? ");

  for (int z = 0; z < height; z++)
    {
    for (int x = height - 1; x > 0; x--)
    {
        printf(" ");
    }
    for (int y = 0; y < z; y++)
    {
        printf("#");
    }

    printf(" ");

    for (int y = 0; y < z; y++)
    {
        printf("#");
    }
    printf("\n");
    }
}
