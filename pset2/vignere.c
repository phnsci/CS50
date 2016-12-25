#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

typedef int bool;
#define true 1
#define false 0

// test if the input string contains only alphabet
bool isAlpha(char *);

// get the character alphabet order
int getNum(char );


int main(int argc, char *argv[])
{
	char *arr;				// string 
	char *k;					// vignere key
	
	// check number of command line arguments
	if (argc != 2) 					return 1;
	if (!isAlpha(argv[1]))	return 1;

	// assign key to vignere key
	k = argv[1];

	// get input string
	do 
	{
		arr = getString();
	} while (arr == NULL);

	// iterate through each characters in string
	for (int i = 0, j = 0; i < strlen(arr); i++) 
	{
		// if character is lowercase
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] = 'a' + (arr[i] + getNum(k[j % (int)strlen(k)]) - 'a') % 26;
			j++;
		}
		// if character is uppercase
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			arr[i] = 'A' + (arr[i] + getNum(k[j % (int)strlen(k)]) - 'A') % 26;
			j++;
		}
	}

	printf("%s\n", arr);
	
	return 0;
}

bool isAlpha(char *arr)
{
	int i = 0;
	while (i < strlen(arr))
	{
		if(!((arr[i] >= 'a' && arr[i] <= 'z') ||
			(arr[i] >= 'A' && arr[i] <= 'Z')))
			return false;
		i++;
	}

	return true;
}

int getNum(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
}
