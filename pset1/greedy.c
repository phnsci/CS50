#include <stdio.h>
#include <stdlib.h>
#include "checknum.h"

#define QUATER 25
#define DIME 	 10
#define NICKLE 5
#define PENNY  1

float roundFloat(float );

int main() 
{

	int count = 0;			// # of coins in exchange
	float cfloat = 0;		// float input from user

	// get valid float
	while (cfloat == 0)
	{
		printf("Enter change: ");
		cfloat = getFloat();
	}

	// multiply by 100 and cast to int
	int cint = (int)(cfloat * 100.0f);

	while (cint >= PENNY)
	{
		if (cint >= QUATER)
			cint -= QUATER;
		else if (cint >= DIME)
			cint -= DIME;
		else if (cint >= NICKLE)
			cint -= NICKLE;
		else 
			cint -= PENNY;
		
		// increment counter each time we get coin	
		count++;
	}

	printf("%d\n", count);

	return 0;
}


