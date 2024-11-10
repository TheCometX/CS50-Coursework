#include <stdio.h>
#include <cs50.h>

int main(void)
{
  long cardNum = get_long("Number: ");
  int length = 0;
  for (int x = 10; x < cardNum; x++)
  {
    length += 1;
  }
  printf("%i", length);
}
