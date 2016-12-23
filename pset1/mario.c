#include <stdio.h>
#include <stdlib.h>
#include "checknum.h"

int main() 
{
	int height = 0;
	int check;

	// get mario pyramid height
	while (height == 0)
	{
		printf("Height: ");
		height = getInt();
	}

	// length of each pyramid layer
	int length = height + 2;

	// memory needed to prinout the pyramid
	int mem = length * height;
	
	// allocate a char array
	char *pyramid;
	pyramid = (char *)malloc(mem);
	
	// generate pyramid in each layer
	for (int i = 0; i < height; i++)
	{
		int j;
		
		// assign space
		for (j = 0; j < length - (i + 2) - 1; j++) 
			pyramid[i * length + j] = ' ';

		// assign #
		for ( ; j < length - 1; j++)
			pyramid[i * length + j] = '#';
		
		// append newline character at the end of each layer
		pyramid[i * length + length - 1] = '\n';
	}
	
	// terminate the array by null 
	pyramid[mem] = 0x00;
	
	printf("%s", pyramid);

	// free memory
	free(pyramid);

	return 0;
}
