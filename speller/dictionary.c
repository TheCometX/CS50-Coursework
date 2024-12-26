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

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    for (node* current = table[index]; current != NULL; current = current->next)
    {
        if (strcmp(current->word, word))
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int index = 0;
    for (int x = 0, len = strlen(word); x < len; x++)
    {
        char c = word[x];
        if (c > 90)
        {
            index += (c-32);
        }
        else
        {
            index += c;
        }
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
    char word[LENGTH];

    while (fscanf(dict, "%s", word) != EOF)
    {
        node* w = malloc(sizeof(node));
        if (w == NULL)
        {
            return false;
        }
        strcpy(w->word, word);
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return tableSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int listsEmpty = 0;
    for (int x = 0; x < N; x++)
    {
        node* list = table[x];
        if (list == NULL)
        {
            listsEmpty++;
            continue;
        }
        else
        {
            for (node* current = table[x]; current != NULL; current = current->next)
            {
                node* next = current->next;
                free(current);
                current = next;
            }
            listsEmpty++;
        }
    }
    if (listsEmpty == 1000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

