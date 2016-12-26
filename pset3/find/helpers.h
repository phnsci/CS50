/**
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);


/**
	* Implements quicksort
	*/
void quickSort(int values[], int left, int right);

/**
	* Quicksort partition
	*/
int partition(int values[], int left, int right);
