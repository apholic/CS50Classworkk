#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

string input(void);
int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void) 
{
    string text = input();

    int letters = count_letters(text);
    // printf("%d letters\n ", letters);

    int words = count_words(text);
    // printf("%d words\n", words);

    int sentences = count_sentences(text);
    //printf("%d sentences\n", sentences);

    //TO DO: calculate grade level using the Coleman-Liau intex: grade = 0.0588 * L - 0.296 * S - 15.8
    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    int rgrade = round(grade);

    // TO DO: Print grade level.
    if (rgrade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (rgrade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", rgrade);
    }

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

//TO DO: Count the number of letters. Exclude punctuations and characters that are not letters.

int count_letters(string text) 
{   
    int letters = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
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

// TO DO: Count the number of words. Count spaces. Identify spaces in a row as one space.
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

//TO DO: Count the number of sentences. Identify sentences as ending with '.', '!', or '?'

int count_sentences(string text)
{
    int sentences = 0; 
    int sum = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if ((text[i - 1] >= 'A') && (text[i - 1] <= 'z') && ((text[i] == '.') || (text[i] == '?') || (text[i] == '!')))
        {
            sentences = sentences + 1;
        }
    }
    return sentences;
}
