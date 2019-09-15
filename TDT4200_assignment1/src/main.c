#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"

#define XSIZE 2560 // Size of before image
#define YSIZE 2048

int main() {
	uchar *image = calloc(XSIZE * YSIZE * 3, 1); // Three uchars per pixel (RGB)
	readbmp("resource/before.bmp", image);

	invert(image, XSIZE, YSIZE);

	int factorX = 2, factorY = 2;
	uchar *imageScaled = calloc(XSIZE * factorX * YSIZE * factorY * 3, 1);
	scale(image, XSIZE, YSIZE, factorX, factorY, imageScaled);


	savebmp("after.bmp", imageScaled, XSIZE*factorX, YSIZE*factorY);
	free(image);
	free(imageScaled);
	return 0;
}
