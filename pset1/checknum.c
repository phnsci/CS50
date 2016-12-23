#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXBUFFERSIZE 80

char buffer[MAXBUFFERSIZE];			// stdin buffer


/**
	clear remaining input buffer
	including the newline character 
	at the end
*/
void clearBuffer() 
{
	char ch;
	ch = getchar();

	// get all stdin buffer until reaching newline 
	while (ch != '\n')
		ch = getchar();
}

/**
	check if user enter a valid non-negative number
	@return an integer if valid input, a 0 if invalid
*/
int getInt() {
	char ch;											// handle individual user input
	char char_count = 0;					// stdin buffer length

	ch = getchar();								// get char from stdin buffer

	// return invalid if user enter nothing	
	if (ch == '\n')
	{
		buffer[0] = 0x00;
		return 0;
	}

	// iterate through stdin buffer 
	while ((ch != '\n') && (char_count < MAXBUFFERSIZE)) 
	{
		// append to buffer string if the input is valid
		if ((ch >= '0') && (ch <= '9'))
		{
			buffer[char_count++] = ch;
			ch = getchar();
		}
		// if not, clear stdin buffer and return 0
		else
		{
			buffer[0] = 0x00;
			clearBuffer();
			return 0;
		}
	}

	// null terminate buffer at the end
	buffer[char_count] = 0x00;
	
	return atoi(buffer);
}

/**
	check if user enter a valid non-negative float
	@return the float if valid, 0 if not valid
*/
float getFloat() {
	char ch;											// handle individual user input
	char char_count = 0;					// stdin buffer length
	bool decimalFlag =  false; 		// decimal flag 
	

	ch = getchar();								// get char from stdin buffer

	// return invalid if user enter nothing	
	if (ch == '\n')
	{
		buffer[0] = 0x00;
		return 0;
	}

	// iterate through stdin buffer 
	while ((ch != '\n') && (char_count < MAXBUFFERSIZE)) 
	{
		// append to buffer string if the input is valid
		if ((ch >= '0') && (ch <= '9'))
		{
			buffer[char_count++] = ch;
			ch = getchar();
		}
		else if ((ch == '.') && (decimalFlag == false))
		{
			buffer[char_count++] = ch;
			decimalFlag = true;
			ch = getchar();
		}
		// if not, clear stdin buffer and return 0
		else
		{
			buffer[0] = 0x00;
			clearBuffer();
			return 0;
		}
	}

	// null terminate buffer at the end
	buffer[char_count] = 0x00;
	printf("%s\n", buffer);	
	return atof(buffer);
}
