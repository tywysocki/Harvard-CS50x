#include <stdio.h>
#include <cs50.h>

// This program prompts the user for their name and responds with a greeting
int main(void)
{
    string name = get_string("What is your name? ");  // Ask the user for their name
    printf("hello, %s\n", name);                      // Greet the user by user input
}