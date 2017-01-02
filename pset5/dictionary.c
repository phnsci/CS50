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
#include <ctype.h>

#include "dictionary.h"

// number of words in dictionary
int num_word = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
	// initialize temp node
	node* temp;
	temp = root;

	// check each character in string
	for (int i = 0; i < strlen(word); i++)
	{	
		int index = 0;
		if (word[i] == '\'')
			index = ALPHA - 1;
		else
			index = tolower(word[i]) - 'a';
	
		// if the string not appear in the dictionary
		if (temp->arr[index] == NULL)
			return false;

		// keep iterate through the tries
		temp = temp->arr[index];
	}

	// check is_word flag at the end of each string 
	if (temp->is_word) 
		return true;
	else
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
	root = malloc(sizeof(node));

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

		// increment number of words
		num_word++;
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
    return num_word;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
	unload_element(root);
    
    return true;
}

/**
  * Unload individual elements in node's array
  */
void unload_element(node *n)
{
	// search for exist node in array
	for (int i = 0; i < ALPHA; i++)
	{
		if (n->arr[i] != NULL)
			unload_element(n->arr[i]);
	}

	// free memory comprised by node
	free(n);
}
		
