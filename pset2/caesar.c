#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

int main(int argc, char* argv[])
{
	int k = 0;			// caesar key
	char *arr;			// string 

	// check command line argument
	if (argc != 2)
		return 1;

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
