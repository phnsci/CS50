/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open dictionary
	FILE* dict = fopen(dictionary, "r");
	if (dict == NULL)
	{
		printf("Cannot load dictionary\n");
		return false;
	}

	// initialize tries root node
	node *root = malloc(sizeof(node));

	// initialize dictionary word
	char *word = malloc(sizeof(char) * LENGTH);

	// read each words in dictionary
	// and build a tries data structure
	while (fgets(word, LENGTH, dict) != NULL)
	{
		node* temp;
		temp = root;

		int length = strlen(word) - 1;
		// iterate each characters
		for (int i = 0; i < length; i++)
		{
			int index = 0;
			// if get SPECIAL character
			if (word[i] == '\'')
				index = ALPHA - 1;
			else
				index = word[i] - 'a';

			// allocate memory if the node at given index is empty
			if (temp->arr[index] == NULL)
				temp->arr[index] = malloc(sizeof(node));
			
			// traverse in the tries if the word is not finished
			if (i < length - 1)
				temp = temp->arr[index];
			// else set is_word to true
			else
				temp->arr[index]->is_word = true;
		}
	}

	// close dictionay
	fclose(dict);

	return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
