#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
  int length = 1;
  long cardNum = get_long("Number: ");
  for (int x = 10; x < cardNum; )
  {
    x *= 10;
    length += 1;
  }
  int total = 0;
  for (int m = pow(10, length); m > 0; m /= 100)
  {
    int result = cardNum / m;
    total += result;
  }
  printf("%i", total);
}
