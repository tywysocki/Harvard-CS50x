// Recovers jpeg images from memory card

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error occured while opening file.\n");
        return 1;
    }

    typedef uint8_t BYTE;
    BYTE buffer[BLOCK];
    size_t bytes_read;

    bool is_first_jpeg = false; // Is this the first jpeg?
    bool jpeg_found = false; // Is a jpeg found?

    FILE *current_file; // Current file
    char file_name[100]; // Current file name
    int file_counter = 0; // Current file number

    // OPEN FILE (memory card)
    while (true)
    {
        // Read 512 bytes to buffer, repeat until memory card's end.
        bytes_read = fread(buffer, sizeof(BYTE), BLOCK, file);
        if (bytes_read == 0)
        {
            break; // END OF FILE, fread returns 0
        }

        // Check for jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If jpeg found...
            jpeg_found = true;

            // If first jpeg, mark first jpeg
            if (!is_first_jpeg)
            {
                is_first_jpeg = true;
            }
            // Else, close file being written to and open a new one.
            else
            {
                // Close current file
                fclose(current_file); // ###.jpg
            }
            // Open new file
            sprintf(file_name, "%03i.jpg", file_counter);
            current_file = fopen(file_name, "w");
            fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            file_counter++;
        }
        else
        {
            // Continue writing if jpeg is found
            if (jpeg_found)
            {
                fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            }
        }
    }
    // Close files
    fclose(file); // Raw file
    fclose(current_file); // Current file (last file written to)
    return 0;
}