#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "checknum.h"


int main() 
{
	long long credit = 0;			// credit card number
	long long copy = 0;				// copy of credit card number
	int size = 0 ;						// number of digits in credit card
	int checkSum = 0;					// check sum
	bool valid = false;				// validity of check sum

	// get valid long long number
	while (credit == 0)
	{
		printf("Number: ");
		credit = getLongLong();
	}

	// copy credit card 
	copy = credit;

	// get number of digits in credit card
	while (copy > 0)
	{
		copy /= 10;
		size++;
	}

	char *buffer;			// credit card storage in char array
	buffer = (char *)malloc(size);
	
	// store credit card number in char array
	sprintf(buffer, "%llu", credit);	

	// sum up other digit, starting with the second-to-last digit
	for (int i = 1; i < size; i += 2)
	{
		int temp = (buffer[i] - '0') * 2;
		printf("temp: %d\n", temp);
		if (temp >= 10)
		{
			checkSum += 1;				// add 1  
			temp = temp % 10;
		}

		checkSum += temp;
	}
	printf("Check sum: %d\n", checkSum);

	// sum up with other digits
	for (int i = 0; i < size; i += 2)
	{
		printf("temp: %d\n", buffer[i] - '0');
		checkSum += (buffer[i] - '0');
	}

	// test check sum
	if (checkSum % 10 == 0)
		valid = true;

	if (valid == true)
	{
		// test american express
		if (buffer[0] == '3' && size == 15) 
		{
			switch (buffer[1]) 
			{
				case '4':
				case '7':
					printf("American Express\n");
					break;
				default:
					printf("Invalid\n");
			}
		}
		// test master card
		else if (buffer[0] == '5' && size == 16)
		{
			switch (buffer[1])
			{
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					printf("Master Card\n");
				default:
					printf("Invalid\n");
			}
		}
		// test visa card
		else if (buffer[0] == '4')
		{
			if ((size == 13) || (size == 16))
			{
				printf("Visa Card\n");
			}
			else 
				printf("Invalid\n");
		}
	}
	else
	{
		printf("Invalid\n");
	}
	
	return 0;
}
