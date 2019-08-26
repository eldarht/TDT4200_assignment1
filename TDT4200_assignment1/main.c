#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"

int main() {
	uchar *image=calloc(XSIZE * YSIZE * 3, 1); // Three uchars per pixel (RGB)
	readbmp("before.bmp", image);

	// Alter the image here

	savebmp("after.bmp", image, XSIZE, YSIZE);
	free(image);
	return 0;
}
