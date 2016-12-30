#include <stdio.h>
#include <stdlib.h> 
#include "jpg.h"

// define boolean type
typedef int bool;
#define true 1
#define false 0

// opening output file status
bool opening = false;

// function prototype
bool checkSignature(BLOCK );

int main(int argc, char* argv[])
{
	// memory block
	BLOCK block;

	// infile string name
	char* infile = "card.raw";

	// open input file
	FILE* inptr = fopen(infile, "r");
	if (inptr == NULL)
	{
		printf("Could not open %s.\n", infile);
		return 1;
	}

	// number of jpeg files
	int num = 0;

	// read infile in block of 512 BYTE or 128 DWORD
	while (fread(&block, sizeof(block), 1, inptr) != 0)
	{
		
		// if find the new signature
		bool found = checkSignature(block);
		
		if (found)
		{
			printf("found: %d\n", num++);
		}
	}

	return 0;		
}


int addr = 0;

/**
	* Check block signature
	*/
bool checkSignature(BLOCK block)
{
	// get the first four bytes of block
	BYTE b0 = block.bytes[0];
	BYTE b1 = block.bytes[1];
	BYTE b2 = block.bytes[2];
	BYTE b3 = block.bytes[3];

	// compare the first four bytes to JPG signature
	for (int i = 0; i < sizeD; i++)
	{
		if (b0 == signature[i][0] && b1 == signature[i][1] &&
				b2 == signature[i][2] && b3 == signature[i][3])
			return true;
	}
	return false;
}
