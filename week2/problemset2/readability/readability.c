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
    int sum = 0;
    int l = strlen(text);
    char exclusion[] = {' ', '.', '?', '!', '"'};  //I want to create an exclusion rule that includes punctuations and spaces
    int e = strlen(exclusion);
    for ( int i = 0; i < l; i++)
    {
        for (int p = 0; p < e; p++)  //here I had a outbound problem but I dont't know why
        {
            if (text[i] != exclusion[p])
            {
                letters = letters + 1;
            }
            else 
            {
                letters = letters + 0;
            }
        }
        sum = sum + letters;

    }

    return sum;
}

//TO DO: calculate grade level using the Coleman-Liau intex: index = 0.0588 * L - 0.296 * S - 15.8

// TO DO: Print grade level.