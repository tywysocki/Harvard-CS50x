#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// This program tests the readability of a text input from the user using the Coleman-Liau index.
// The output shows the user what U.S. grade level is needed to understand the text.
int main(void)
{
    string text = get_string("Text: ");                       // Prompt user to input text

    int letters = count_letters(text);                        // Calculate # of words, letters and sentences in the user input
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / (float) words) * 100;        // Calculate Coleman-Liau parameters L and S
    float S = ((float) sentences / (float) words) * 100;      // (float), temporarily changes a variable's type

    int index = round((0.0588 * L) - (0.296 * S) - 15.8);     // Calculate the Coleman-Liau index

    if (index < 1)          // Display the grade needed to understand the text inputted by the user
    {
        printf("Before Grade 1\n"); 
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %d\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)                  // Begin code for the function count_letters
{
    int letter = 0;                             // Initialize variable that stores # of letters in text
    for (int i = 0; i < strlen(text); i++)      // Loop through each characacter in text
    {
        if (isalpha(text[i]))                   // If a character is alphabetical add 1 to the variable letter
        {
            letter++;
        }
    }
    return letter;                              // Return the number of letters in text
}

int count_words(string text)                    // Begin code for the function count_words
{
    int word = 1;                               // Initialize variable that stores # of words in text
    for (int i = 0; i < strlen(text); i++)      // Loop through each character in text
    {
        if (isspace(text[i]))                   // If a character is " " add 1 to variable space
        {
            word++;
        }
    }
    return word;                                // Return the number of words in text. PLEASE NOTE: style50 wanted the code in lines 64 - 66 to be weird like that.
}

int count_sentences(string text)                                  // Begin code for the function count_sentences
{
    int sentence = 0;                                             // Initialize variable that stores the number of sentences in text

    for (int i = 0; i < strlen(text); i++)                        // Loop through each char in text
    {
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)      // If char = "!", "?" or "." we add 1 to the variable sentence.
        {
            sentence++;
        }
    }
    return sentence;                                              // Return the number of sentences in text
}