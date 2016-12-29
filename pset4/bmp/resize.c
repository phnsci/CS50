#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
	// ensure proper usage
	if (argc != 4)
	{
		printf("Usage: ./resize n infile outfile\n");
		return 1;
	}

	// resize value
	int n = atoi(argv[1]);

	// remember filenames
	char* infile = argv[2];
	char* outfile = argv[3];

	// open input file 
	FILE* inptr = fopen(infile, "r");
	if (inptr == NULL)
	{
		printf("Could not open %s.\n", infile);
		return 2;
	}

	// open output file
	FILE* outptr = fopen(outfile, "w");
	if (outptr == NULL)
	{
		fclose(inptr);
		fprintf(stderr, "Could not create %s.\n", outfile);
		return 3;
	}

	// read infile's BITMAPFILEHEADER
	BITMAPFILEHEADER bf;
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

	// read infile's BITMAPINFOHEADER
	BITMAPINFOHEADER bi;
	fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

	// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
	if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || 
			bi.biBitCount != 24 || bi.biCompression != 0)
	{
		fclose(outptr);
		fclose(inptr);
		fprintf(stderr, "Unsupported file format.\n");
		return 4;
	}

	// determine padding for infile scanlines
	int infilePadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

	// determine infile biWidth
	int infileBiWidth = bi.biWidth;
	int infileBiHeight = abs(bi.biHeight);

	// update outfile BITMAPINFOHEADER after resize
	bi.biWidth *= n;
	bi.biHeight *= n;
	int biSize = 40;
	bi.biSize = biSize;
	int outfilePadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
	int biSizeImage = ((bi.biWidth + outfilePadding) * abs(bi.biHeight)) * 
		(int)sizeof(RGBTRIPLE);
	bi.biSizeImage = biSizeImage;

	// update outfile BITMAPFILEHEADER after resize
	int bfSize = bi.biSizeImage + 54;
	bf.bfSize = bfSize;

	// write outfile's BITMAPFILEHEADER
	fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

	// write outfile's BITMAPINFOHEADER
	fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

	// iterate over infile's scanlines
	for (int i = 0; i < infileBiHeight; i++)
	{
		// duplicate each scanline n times
		for (int w = 0; w < n; w++)
		{
			// iterate over each pixels in scanline
			for (int j = 0; j < infileBiWidth; j++)
			{
				// temporary storage
				RGBTRIPLE triple;

				// read RGB triple from infile
				fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

				// write RGB triple to outfile n times
				for (int l = 0; l < n; l++)
					fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
			}

			// then add it back (to demonstrate how)
			for (int k = 0; k < outfilePadding; k++)
			{
				fputc(0x00, outptr);
			}

			// move infile pointer to beginning of scanline
			fseek(inptr, -(infileBiWidth * (int)sizeof(RGBTRIPLE)), SEEK_CUR);
		}

		// move infile pointer to the end of scanline
		// including infile padding
		fseek(inptr, infileBiWidth * (int)sizeof(RGBTRIPLE) + infilePadding, SEEK_CUR);
	}

	// close infile
	fclose(inptr);

	// close outfile
	fclose(outptr);

	// that's all folks
	return 0;
}
