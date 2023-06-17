#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string input(void);
int count_letters(string);


int main(void) 
{
    string text = input();

    int letters = count_letters(text);
    printf ("letters: %d\n", letters);
}

//TO DO: prompt user imput

string input(void)
{
    string input; int l;
    l = strlen(input);
    do 
    {
        input = get_string ("Text:");
    }
    while (l < 1);
    return input;
}

//TO DO: Count the number of letters, words, and sentences.

int count_letters(string text) 
{   
    int letters = 0;
    for ( int i = 0, l = strlen(text); i < l; i++)
    {   
            if (text[i] >= 'A' && text[i] <= 'z') //exclude chars other than letters
            {
                letters = letters + 1;
            }
            else 
            {
                letters = letters + 0;
            }
    }

    return letters;
}

//TO DO: calculate grade level using the Coleman-Liau intex: index = 0.0588 * L - 0.296 * S - 15.8

// TO DO: Print grade level.