#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"

// save 24-bits bmp file, buffer must be in bmp format: upside-down
void savebmp(char *name,uchar *buffer,int x,int y) {
	FILE *f=fopen(name,"wb");
	if(!f) {
		printf("Error writing image to disk.\n");
		return;
	}
	unsigned int size=x*y*3+54;
	uchar header[54]={'B','M',size&255,(size>>8)&255,(size>>16)&255,size>>24,0,
                    0,0,0,54,0,0,0,40,0,0,0,x&255,x>>8,0,0,y&255,y>>8,0,0,1,0,24,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	fwrite(header,1,54,f);
	fwrite(buffer,1,x*y*3,f);
	fclose(f);
}

// read bmp file and store image in contiguous array
void readbmp(char* filename, uchar* array) {
	FILE* img = fopen(filename, "rb");   //read the file
	uchar header[54];
	fread(header, sizeof(uchar), 54, img); // read the 54-byte header

  // extract image height and width from header
	int width = *(int*)&header[18];
	int height = *(int*)&header[22];
	int padding=0;
	while ((width*3+padding) % 4!=0) padding++;

	int widthnew=width*3+padding;
	uchar* data = calloc(widthnew, sizeof(uchar));

	for (int i=0; i<height; i++ ) {
		fread( data, sizeof(uchar), widthnew, img);
		for (int j=0; j<width*3; j+=3) {
			array[3 * i * width + j + 0] = data[j+0];
			array[3 * i * width + j + 1] = data[j+1];
			array[3 * i * width + j + 2] = data[j+2];
		}
	}
	fclose(img); //close the file
}


void scale(uchar *image, int sizeX, int sizeY, int factorX, int factorY, uchar *imageScaled){
	
	for (int i = 0; i < sizeY; ++i)
	{
		for (int j = 0; j < sizeX; ++j)
		{
			for (int k = 0; k < factorY; ++k)
			{
				for (int l = 0; l < factorX; ++l)
				{		//  Offset of rows		offset of duplicate columns   offset of duplicate row/column 
					imageScaled[(k*sizeX*factorX*3) + (j*3*factorX) + (i*factorY*3*sizeX*factorX)+l*3+0] = image[3*j+(i*sizeX*3)+0];
					imageScaled[(k*sizeX*factorX*3) + (j*3*factorX) + (i*factorY*3*sizeX*factorX)+l*3+1] = image[3*j+(i*sizeX*3)+1];
					imageScaled[(k*sizeX*factorX*3) + (j*3*factorX) + (i*factorY*3*sizeX*factorX)+l*3+2] = image[3*j+(i*sizeX*3)+2];
				}

			}
		}
	}
}

void invert(uchar *image, int sizeX, int sizeY){

	for (int i = 0; i < sizeX * sizeY * 3; ++i)
	{
		// I have not used .bmp before so i assume the rgb values can be used here as 256 bit colors.
		image[i] = 255 - image[i]; 
	}
}
