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
	BLOCK block;									// memory block
	char* infile = "card.raw"; 		// infile string name
	char* outfile = malloc(7);		// output file name
	int name = 0;									// output file name counter
	bool isOpening = false;				// opening output file status
	FILE* outptr = NULL;					// output file pointer

	// open input file
	FILE* inptr = fopen(infile, "r");
	if (inptr == NULL)
	{
		printf("Could not open %s.\n", infile);
		return 1;
	}

	// read infile in block of 512 BYTE or 128 DWORD
	while (fread(&block, sizeof(block), 1, inptr) != 0)
	{
		bool found = checkSignature(block);
	
		// if found new signature
		if (found)
		{
			// if the program already open an output file
			if (isOpening)
			{
				// close that file
				fclose(outptr);
				isOpening = false;
			}

			// get the new output file jpg name
			sprintf(outfile, "%03d.jpg", name++);

			// open new file 
			outptr = fopen(outfile, "w");
			if (outptr == NULL)
			{
				printf("Could not open %s.\n", outfile);
				return 2;
			}
			isOpening = true;
		}

		// if the output file is  opened 
		if (isOpening == true && outptr != NULL)
		{
			// write to opened output file
			fwrite(&block, sizeof(block), 1, outptr);
		}
	}

	// close output file
	if (isOpening && outptr != NULL)
	{
		fclose(outptr);
		isOpening = false;
	}

	// close input file
	fclose(inptr);

	return 0;		
}

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
