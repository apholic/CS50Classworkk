#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string input(void);
int count_letters(string);
int count_words(string);

int main(void) 
{
    string text = input();

    int letters = count_letters(text);
    printf("letters: %d\n", letters);

    int words = count_words(text);
    printf("words: %d\n", words);
}

//TO DO: prompt user imput

string input(void)
{
    string input;
    do 
    {
        input = get_string("Text:");
    }
    while (strlen(input) < 1);
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

// TO DO: Count the number of words
int count_words(string text)
{
    int space = 0; 
    int sum = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if ((text[i] == ' ') && (text[i - 1] != ' '))   //delete condition && (text[i + 1] != ' ') 
        {
            space = 1;
        }
        else                                            //I'm not sure about how to inlude cases such as spaces in the beginining or and as well as "..."
        {
            space = 0;
        }

        sum = sum + space;
    }

    int words = sum + 1;

    return words;

}

//TO DO: calculate grade level using the Coleman-Liau intex: index = 0.0588 * L - 0.296 * S - 15.8



// TO DO: Print grade level.