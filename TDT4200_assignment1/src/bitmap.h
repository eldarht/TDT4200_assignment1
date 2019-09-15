#ifndef BITMAP_H
#define BITMAP_H


typedef unsigned char uchar;
void savebmp(char *name, uchar *buffer, int x, int y);
void readbmp(char *filename, uchar *array);
void readbmp(char *filename, uchar *array);

/**
 * @brief      Scales the image in both x and y direction.
 *
 * @param      image   	The image
 * @param[in]  sizeX  	The size of the input image width
 * @param[in]  sizeY  	The size of the input image hight
 * @param[in]  factorX  The factor to scale in x direction
 * @param[in]  factorY  The factor to scale in y direction
 * @param 	   scaledImage The result of the image scaling
 */
void scale(uchar *image, int sizeX, int sizeY, int factorX, int factorY, uchar *imageScaled);

#endif
