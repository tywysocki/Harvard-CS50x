#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Encrypts messsages using a substitution cipher
int main(int argc, string argv[])
{
    if (argc != 2)    // Only 1 command line argument is allowed
    {
        printf("Program Usage: ./substitution key\n");  // Provide Usage Directions
        return 1;
    }

    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))    // The key must be alphabetical
        {
            printf("Key elements must be alphabetical\n");    // Provide Usage Directions
            return 1;
        }
    }

    if (strlen(key) != 26)
    {
        printf("Key must have 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)    // Each element in the key must be unique
    {
        for (int j = i + 1; j < strlen(key); j++)    // Check if element i has any duplicates
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Usage: ./substitution key\n");    // Provide usage directions
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");    // Prompt user for the message

    for (int i = 0; i < strlen(key); i++)    // Convert lowercase key elements to uppercase
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }

    printf("ciphertext: ");    // Display the ciphertext

    for (int i = 0; i < strlen(plaintext); i++)  // Loop through each element of plaintext
    {
        if (isupper(plaintext[i]))    // If the plaintext element is uppercase:
        {
            int letter = plaintext[i] - 65;    // Find position of plaintext element in ciphertext
            printf("%c", key[letter]);    // Display that element in ciphertext
        }
        else if (islower(plaintext[i]))    // If plaintext element is lowercase:
        {
            int letter = plaintext[i] - 97;    // Find position of plaintext element in ciphertext
            printf("%c", key[letter] + 32);    // Display plaintext element in ciphertext
        }
        else
        {
            printf("%c", plaintext[i]);    // If non-alphabetical display plaintext
        }
    }
    printf("\n");
}