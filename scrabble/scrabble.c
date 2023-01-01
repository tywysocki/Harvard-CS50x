#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// This is a program that simulates the game Scrabble. Players enter a word; the highest scoring word wins.

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");       // get_string collects player 1's word
    string word2 = get_string("Player 2: ");       // get_string collects player 2's word

    // Score both words
    int score1 = compute_score(word1);             // Compute player 1's score
    int score2 = compute_score(word2);             // Compute player 2's score

    if (score1 < score2)                           // Display statement if player 2 wins
    {
        printf("Player 2 Wins!\n");
    }
    else if (score2 < score1)                      // Display statement if player 1 wins
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 == score2)                     // Display statement if it's a tie
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)                     // Begin code for compute_score
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)         // CHANGE COMMENTS WITH *****
    {
        if (isupper(word[i]))                      //***** convert ASKII index to word index for uppercase letters
        {
            score = score + POINTS[word[i] - 65];  // Sum the scores of each letter
        }
        if (islower(word[i]))                      //***** convert ASKII index to word index for lowercase letters
        {
            score = score + POINTS[word[i] - 97];  // Sum the scores of each letter
        }
    }
    return score;
}
