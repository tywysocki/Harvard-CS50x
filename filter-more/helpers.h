// Provides the fucnction prototypes for the functions in filter.c

#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

// NOTE: See how each funcction takes a 2D array called image as an argument.
// image is an array of height specifying how many rows in the array
// each row itself is another array of width many RGBTRIPLEs.
// So if "image" represents the whole picture, then image[0] represents the first row
// and image[0][0] represents the pixel in the upper-left corner of the image

// Example: image[row][column] i.e. pixel in row number 1 and column number 1 is
//          in the middle of the "block" of pixels below. image is just a 2D array
//          of pixels.

// image[0][0] image[0][1] image[0][2]
// image[1][0] image[1][1] image[1][2]
// image[2][0] image[2][1] image[2][2]