#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int length = 1;
  long cardNum = get_long("Number: ");
  for (int x = 10; x < cardNum; )
  {
    x *= 10;
    length += 1;
  }
  for (int y = 10 * length; y > 0;);
  {
    y /= 10;
    printf("%i\n", y);
  }
}
