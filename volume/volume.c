// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);  // atof() converts a string to a float

    uint8_t header_buffer[HEADER_SIZE]; // Buffer array - data were reading will be stored here

    // Copy header from input file to output file
    fread(&header_buffer, HEADER_SIZE, 1, input);
    fwrite(&header_buffer, HEADER_SIZE, 1, output);

    // fread(Buffer, Byte Size, Header size, input file to read)
    // fwrite(^, ^, ^, output file to write)

    int16_t buffer; // Buffer Array for data modification

    // Read samples from input file and write updated data to output file
    while (fread(&buffer, sizeof(int16_t), 1, input))  // Use & for variables
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    fclose(input);
    fclose(output);
}

/////////////////////////// NOTES ////////////////////////////////////////////////////////////

// uint8_t - A type that stores unsigned integers that are 8 bits (1-byte large)
//           Useful anytime you want to represent just a generic byte of data. For
//           example, if youre trying to read in a 44 byte header you might use an
//           array of 44 of these unsigned integers of 8-bit size.

// int16_t - Stores signed integers, meaning they could be positive, negative or 0
//           of 16-bits (2-bytes) each. This is ultimately the best since we know
//           that each sample is 2-bytes large.