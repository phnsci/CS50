#include <stdio.h>
#include <stdlib.h>
#include "checknum.h"

int main() 
{
	int height = 0;				// mario pyramid height
	int length = 0;				// length of each pyramid layer

	while (height == 0)
	{
		printf("Height: ");
		height = getInt();
	}

	length = height * 2 + 3;

	// memory needed to printout the pyramid
	int mem = length * height + 1;

	// allocate a char array
	char *pyramid = (char *)malloc(mem);

	for (int i = 0; i < height; i++)
	{
		int j = 0;

		// assign left space
		for (int k = 0; k < height - i - 1;  k++)
		{
			pyramid[i * length + j] = ' ';
			j++;
		}

		// assign left pyramid
		for (int k = 0; k < i + 1; k++)
		{
			pyramid[i * length + j] = '#';
			j++;
		}


		// assign two middle space
		pyramid[i * length + j] = ' ';
		j++;
		pyramid[i * length + j] = ' ';
		j++;
		

		// assign right pyramid
		for (int k = 0; k < i + 1; k++)
		{
			pyramid[i * length + j] = '#';
			j++;
		}


		// assign right space
		for (int k = 0; k < height - i - 1; k++)
		{
			pyramid[i * length + j] = ' ';
			j++;
		}

		// assign newline character at the end of each layer
		pyramid[i * length + j] = '\n';
	}

	// terminate the array by null
	pyramid[mem - 1] = 0x00;

	printf("%s", pyramid);

	// free memory
	free(pyramid);

	return 0;
}
