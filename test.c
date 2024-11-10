#include <stdio.h>
#include <cs50.h>

int main(void)
{
  long cardNum = get_long("Number: ");
  for (int x = 10, int length = 1; x < cardNum; )
  {
    x *= 10;
    length += 1;
  }
}
