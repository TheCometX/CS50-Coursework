#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

int main(int argc, string argv[])
{
    candidate person[argc];
    for (int y = 0; y < argc; y++)
    {
        person[y].name = argv[y+1];
    }
    
}
