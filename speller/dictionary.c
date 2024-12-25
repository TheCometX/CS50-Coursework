// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];
long int size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int index = 0;
    for (int x = 0, len = strlen(word); x < len; x++)
    {
        char c = word[x];
        index += c;
    }
    index %= N;
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        return false;
    }
    while(fscanf(dict, "%s", n->word) != EOF)
    {
        n->next = NULL;

        unsigned int index = hash(n->word);

        if (table[index] == NULL)
        {
            table[index] = n;
            return true;
        }
        else
        {
            for (node* current = table[index]; current != NULL; current = current->next)
            {
                if (current->next == NULL)
                {
                    current->next = n;
                    return true;
                }
            }
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
