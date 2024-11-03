#include <stdio.h>
#include <cs50.h>

void stair(int z);   
int main(void)
{
  int height;
  do
  {
    height = get_int("What's the height? ");      //It will be asked until number be higher than 0
  }
  while (height < 0);
  for (int z = 1; z <= height; z++)   //z start in 1 because if start in 0 the first repetition will just print a white line
    {
    for (int x = height - z; x > 0; x--) // This loop make the spaces before #
    {
        printf(" ");
    }
    stair(z);
    printf("  ");   //The space between #
    stair(z);
    printf("\n");   //Break a line for next row start
    }
}

void stair(int z) //It prints the # in each row, z is the number of # in row
{
    for (int y = 0; y < z; y++)
    {
        printf("#");
    }
}
