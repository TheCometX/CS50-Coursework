#include <stdio.h>
#include <cs50.h>

void stair(int z);
int main(void)
{
  int height;
  do
  {
    height = get_int("What's the height? ");
  }
  while (height < 0);
  for (int z = 0; z <= height; z++)
    {
    for (int x = height - z; x > 0; x--)
    {
        printf(" ");
    }
    stair(z);
    printf("  ");
    stair(z);
    printf("\n");
    }
}

void stair(int z)
{
    for (int y = 0; y < z; y++)
    {
        printf("#");
    }
}
