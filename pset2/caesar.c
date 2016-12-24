#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

typedef int bool;
#define true 1
#define false 0

bool isNumber(char *);

int main(int argc, char* argv[])
{
	int k = 0;			// caesar key
	char *arr;			// string 

	// check number of command line arguments
	if (argc != 2) 					return 1;
	if (!isNumber(argv[1])) return 1;


	// get key from command line
	k = atoi(argv[1]);

	// get input string
	do 
	{
		arr = getString();
	} while (arr == NULL);

	// iterate through each characters in string
	for (int i = 0; i < strlen(arr); i++)
	{
		// if character is lowercase
		if (arr[i] >= 'a' && arr[i] <= 'z')
			arr[i] = 'a' + (arr[i] + k - 'a') % 26;
		// if character is uppercase
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			arr[i] = 'A' + (arr[i] + k - 'A') % 26;
	}

	printf("%s\n", arr);
			
	return 0;
}

bool isNumber(char *arr)
{
	int i = 0;
	while (i < strlen(arr))
	{
		if (!((arr[i] >= '0') && (arr[i] <= '9')))
			return false;
		i++;
	}
	return true;
}
