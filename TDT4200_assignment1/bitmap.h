#ifndef BITMAP_H
#define BITMAP_H

#define XSIZE 2560
#define YSIZE 2048
#define PIXEL(i, j) ((i) + (j)*XSIZE)

typedef unsigned char uchar;
void savebmp(char *name, uchar *buffer, int x, int y);
void readbmp(char *filename, uchar *array);

#endif
