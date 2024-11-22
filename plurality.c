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
    for (int y = 0; y < argc - 1; y++)
    {
        person[y].name = argv[y+1];
    }
    int number = get_int("Number of voters: ");
    for (int x = 0; x < number; x++)
    {
        string vote = get_string("Vote: ");
        for (int z = 0, z < argc - 1; z++)
        {
            if (strcmp(candidate[z].name, vote) == 0)
            {
                candidate[z].votes += 1;
            }
        }
    }
}
