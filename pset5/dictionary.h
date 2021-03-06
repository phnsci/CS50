/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 46		// longest word in dictionary
#define ALPHA 27		// 26 alphabet characters plus 1 special character

/**
  * Tries data structure
  */
typedef struct node
{
	bool is_word;
	struct node* arr[ALPHA];
} node;

/**
  * Initialize Tries root node
  */
node *root;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
  * Unload individual elements in node's array
  */
void unload_element(node *n);

#endif // DICTIONARY_H
