// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // We change the first letter to binary
    int hashWord = (int)(*(word)) % 97;

    return hashWord;

    //return 0;
}
#define LARGE 143091
#define SMALL 2
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    int i;

    // array to store words read from dictionary
    char *words_from_dictionary[SMALL];
    int new_word = 0;

    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    // Read strings from file one at a time
    const char *p = dictionary;
    int nwords = 0;
    while ((fscanf(file, "%s", words_from_dictionary[nwords]) != EOF))
    {
        // Create a loop that looks at each character until '\0'

        // Create a new node for each word
        node *n = malloc(sizeof(node));
        n->next = NULL;

        if (n == NULL)
        {
            return false;
        }

        //if(*p == '\0')

        strcpy(n->word, words_from_dictionary[nwords]); // FIX THIS

        // Hash word to obtain a hash value
        int hashedWord = hash(words_from_dictionary[nwords]);
        // Insert node into hash table at that location

        // If only word in bucket or at end of linked list in current bucket point n->next to NULL
        //n->next = NULL;

        //words_from_dictionary[nwords++] = p;

		if (nwords >= SMALL) // LARGE || SMALL
		{
		    return true;
		}
	}

    // not enough memory to allocate or cant open file
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
