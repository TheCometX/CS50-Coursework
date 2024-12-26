// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;
unsigned int table_size = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    for (node* current = table[index]; current != NULL; current = current->next)
    {
        if (strcasecmp(current->word, word) == 0)
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
    for (int y = 0, l = strlen(word); y < l; y++)
    {
        char c = word[y];
        if (isalpha(c))
        {
            index += tolower(c);
        }
    }
    return index % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(dict, "%s", word) != EOF)
    {
        node* w = malloc(sizeof(node));
        if (w == NULL)
        {
            return false;
        }
        strcpy(w->word, word);
        int index = hash(word);
        w->next = table[index];
        table[index] = w;
        table_size++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return table_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int empty = 0;
    for (int x = 0; x < N; x++)
    {
        node* list = table[x];
        if (list == NULL)
        {
            empty++;
        }
        else
        {
            node* current = list;
            while (current != NULL)
            {
                node* temp = current;
                current = current->next;
                free(temp);
            }
            empty++;
        }
    }
    if (empty == N)
    {
        return true;
    }
    else
    {
        return false;
    }
}

