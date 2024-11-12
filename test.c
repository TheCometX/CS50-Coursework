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
}
