#include <stdio.h>
#include "checknum.h"

int main() 
{
	int min = 0;		// number of minutes
	int bot = 0;		// number of bottles
	
	while (min == 0)
	{
		printf("minutes: ");
		min = getInt();
	}

	bot = 192 * min / 16;

	printf("bottles: %d\n", bot);

	return 0;
}
