#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name, int argc, string argv[]);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name, argc, argv))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name, int argc, string argv[])
{
    for (int x = 0; x < argc; x++)
    {
        if (strcmp(name, argv[x + 1]) == 0)
        {
            preferences[voter][rank] = name;
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // access each candidate
    for (int y = 0; y < voter_count; y++)
    {
        // access each of its preferences
        for (int z = 0; z < candidate_count; z++)
        {
            // access the candidates in candidates[] to compare with preference
            for (int c = 0; c < candidate_count; c++)
            {
                if (strcmp(preferences[y][z], candidates[c].name) == 0)
                {
                    if (candidates[c].eliminated == false)
                    {
                        candidates[c].votes += 1;
                    }
                }
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int more_votes = 0;
    int num_persons = 0;
    for (int a = 0; a < candidate_count; a++)
    {
        if (candidates[a].votes > candidates[more_votes].votes)
        {
            more_votes = a;
        }
        else if (candidates[a].votes == candidates[more_votes].votes)
        {
            num_persons++;
        }
    }
    if (candidates[more_votes].votes > (voter_count / 2) && num_persons == 1)
    {
        printf("%s\n", candidates[more_votes]);
        return true;
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = MAX_VOTERS;
    for (int t = 0; t < candidate_count; t++)
    {
        if (candidates[t].votes < min_votes && candidates[t].eliminated == false)
        {
            min_votes = candidates[t].votes;
        }
    }

    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int more_votes = 0;
    for (int a = 0; a < candidate_count; a++)
    {
        if (candidates[a].votes > candidates[more_votes].votes)
        {
            more_votes = a;
        }
    }
    if (min == more_votes)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int v = 0; v < candidate_count; v++)
    {
        if (candidates[v].votes == min)
        {
            candidates[v].eliminated = true;
        }
    }

    return;
}
