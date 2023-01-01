// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Declare unsigned variables
unsigned int hash_value;
unsigned int word_counter;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    node *cursor = table[hash_value];

    // Loop over the linked list
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return 0;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;

    // Loop through each character in the word
    for (int i = 0; i < strlen(word); i++)
    {
        // Convert each char in word to lowercase
        total += tolower(word[i]);
    }
    // Calculate the index
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];

    // Scan the dictionary for strings until the end of the file (EOF)
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        else
        {
            strcpy(new_node->word, word);
            hash_value = hash(word);
            new_node->next = table[hash_value];
            table[hash_value] = new_node;
            word_counter++;
        }
    }
    // Close the file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_counter > 0)
    {
        return word_counter;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful and false if not
bool unload(void)
{
    // Free linked list
    for (int i = 0; i < N; i++)
    {
        node *head = table[i]; // Points to start (head) of list
        node *cursor = head; // Place cursor at start
        node *temp = head; // Place temp at start
        
        // IMPORTANT: Move cursor, free, AND THEN move temp
        // This is where the memory leak problem happened
        while (cursor != NULL)
        {
            cursor = cursor->next; // Move cursor over
            free(temp); // Free temp
            temp = cursor; // Move temp over
        }
    }
    return true;
}
