// Implementation of the functions declared in helpers.h
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over each pixel inside image using a nested loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            int gray = round((pixel.rgbtBlue + pixel.rgbtRed + pixel.rgbtGreen) / 3.0);

            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_buffer[height][width];

    // Make transformations by reading image in reverse
    // and writing to temporary buffer array.
    for (int i = 0; i < height; i++)
    {
        int k = 0;
        for (int j = width - 1; j >= 0; j--, k++)
        {
            temp_buffer[i][k] = image[i][j];
        }
    }

    // Copy the temporary buffer to a final image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_buffer[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_buffer[height][width];

    // Examine and validate each cell's nieghboring cell.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            int x_coordinates[] = { i - 1, i, i + 1};
            int y_coordinates[] = { j - 1, j, j + 1};

            float total_red = 0;
            float total_green = 0;
            float total_blue = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int current_row = x_coordinates[r];
                    int current_col = y_coordinates[c];

                    if (current_row >= 0 && current_row < height && current_col >= 0 && current_col < width)
                    {
                        RGBTRIPLE pixel = image[current_row][current_col];

                        total_red += pixel.rgbtRed;
                        total_green += pixel.rgbtGreen;
                        total_blue += pixel.rgbtBlue;
                        counter++;
                    }
                }
            }
            temp_buffer[i][j].rgbtRed = round(total_red / counter);
            temp_buffer[i][j].rgbtGreen = round(total_green / counter);
            temp_buffer[i][j].rgbtBlue = round(total_blue / counter);
        }
    }
    // Copy to the final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_buffer[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create buffer array
    RGBTRIPLE temp_buffer[height][width];

    // Implement Sobel filter algorithm
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            int x_coordinates[] = { i - 1, i, i + 1};
            int y_coordinates[] = { j - 1, j, j + 1};

            float Gx_red = 0;
            float Gx_green = 0;
            float Gx_blue = 0;

            float Gy_red = 0;
            float Gy_green = 0;
            float Gy_blue = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int current_row = x_coordinates[r];
                    int current_col = y_coordinates[c];

                    if (current_row >= 0 && current_row < height && current_col >= 0 && current_col < width)
                    {
                        RGBTRIPLE pixel = image[current_row][current_col];

                        Gx_red += Gx[r][c] * pixel.rgbtRed;
                        Gx_green += Gx[r][c] * pixel.rgbtGreen;
                        Gx_blue += Gx[r][c] * pixel.rgbtBlue;

                        Gy_red += Gy[r][c] * pixel.rgbtRed;
                        Gy_green += Gy[r][c] * pixel.rgbtGreen;
                        Gy_blue += Gy[r][c] * pixel.rgbtBlue;
                    }
                }
            }
            // sqrt(Gx^2 + Gy^2) for each color dimension
            int Red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int Green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int Blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Copy to temp. If (RGB value > 255), cap at 255: Else, (use RGB value)
            temp_buffer[i][j].rgbtRed = Red > 255 ? 255 : Red;
            temp_buffer[i][j].rgbtGreen = Green > 255 ? 255 : Green;
            temp_buffer[i][j].rgbtBlue = Blue > 255 ? 255 : Blue;
        }
    }
    // Copy to the final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_buffer[i][j];
        }
    }
    return;
}
