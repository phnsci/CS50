#include <stdint.h>
/**
 * Common Data Types 
 *
 * The data types in this section are essentially aliases for C/C++ 
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE;			// 1 byte
typedef uint16_t WORD;			// 2 bytes
typedef uint32_t DWORD;			// 4 bytes
typedef int32_t  LONG;		

// constant
#define BLOCK_SIZE 128 // DWORD

/**
	* JPEG block size in bytes
	*/
typedef struct
{
	DWORD dword[BLOCK_SIZE];
} __attribute__((__packed__))
BLOCK;

/**
	* Signature of JPEG beginning block
	* The signature marks the beginning of JPEG file
	*/
DWORD signature[] = {0xffd8ffe0, 0xffd8ffe1, 0xffd8ffe2, 0xffd8ffe3, 
										 0xffd8ffe4, 0xffd8ffe5, 0xffd8ffe6, 0xffd8ffe7,
										 0xffd8ffe8, 0xffd8ffe9, 0xffd8ffea, 0xffd8ffeb,
										 0xffd8ffec, 0xffd8ffed, 0xffd8ffee, 0xffd8ffef};

// size of signature array
int sizeSig = 16;
