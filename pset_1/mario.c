#include <stdio.h>
#include <cs50.h>

// This program generates two adjacent pyramids of blocks, "#", with a gap "  " between them.
// The height of the pyramids is based on the users input of 1 through 8
int main(void)
{
    int h;
    do                                            // Start do-while loop for user input
    {
        h = get_int("Height: ");                  // Prompt user for height
    }
    while (h < 1 || h > 8);                       // Reject user input unless integer 1-8 inclusive
    int i, j, k;
    for (i = 0; i < h; i++)                       // Create loop for new line/row
    {
        for (j = 0; j < h - i - 1; j++)           // Create loop for printing spaces in left pyramid
        {
            printf(" ");
        }
        for (k = 0; k <= i; k++)                 // Create loop for printing blocks # in left pyramid
        {
            printf("#");
        }
        printf("  ");                            // Print gap between left and right pyramids
        for (k = 0; k <= i; k++)                 // Create loop for printing blocks # in right pyramid
        {
            printf("#");
        }
        printf("\n");                            // Move to next line/row
    }
}