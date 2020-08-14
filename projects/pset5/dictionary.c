// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

int wordCount = 0;;
//int strcasecmp(const char *string1, const char *string2);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);

    int hashed = hash(word);

    node *cursor = table[hashed];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // From reddit by delipity
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ tolower(word[i]);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    char word1[LENGTH + 1];
    wordCount = 0;


    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        //fclose(fp);
        return false;
    }

    while ((fscanf(fp, "%s", word1)) != EOF)
    {
        //fgetc(fp);
        node *p1 = malloc(sizeof(node));

        if (p1 == NULL)
        {
            unload();
            return false;
        }

        strncpy(p1->word, word1, sizeof(word1));


        // Hash the word
        int hashed = hash(p1->word);

        node *head = table[hashed];

        // If first item at index
        if (head == NULL)
        {
            p1->next = NULL;
        }
        else
        {
            p1->next = table[hashed];
        }
        table[hashed] = p1;
        wordCount++;

    }
    fclose(fp);
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *tmp = NULL;
    node *cursor;

    for (int i = 0; i < N; ++i)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}
