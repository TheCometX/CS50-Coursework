#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

int main(int argc, string argv[])
{
    candidate person[argc];
    for (int y = 1; y < argc; y++)
    {
        person[y].name = argv[y];
    }
    int number = get_int("Number of voters: ");
    for (int x = 0; )
}
