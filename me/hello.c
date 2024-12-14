#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the name in input and print hello 'name' in output
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
