#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int len(string n);

int main(void)
{
  string name = "Vinicius";
  printf("%i", len(name));
}

int len(string n) {
  int x = strlen(n);
  return x;
}
