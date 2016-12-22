#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXBUFFERSIZE 80


/**
	clear remaining input buffer
	including the newline character 
	at the end
*/
void clearbuffer() 
{
	char ch;
	ch = getchar();

	// get all stdin buffer until reaching newline 
	while (ch != '\n')
		ch = getchar();
}

/**
	check if user enter valid integer number
	@return input number if valid input, 0 if not valid
*/
int getInt() {
	char ch;											// handle individual user input
	char buffer[MAXBUFFERSIZE];		// stdin buffer
	char char_count = 0;					// stdin buffer length

	ch = getchar();

	// return invalid if user enter nothing	
	if (ch == '\n')
		return 0;

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
			clearbuffer();
			return 0;
		}
	}

	// null terminate buffer at the end
	buffer[char_count] = 0x00;
	
	// convert buffer string to integer	
	int num = atoi(buffer);
	return num;
}
