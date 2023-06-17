#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text:");
    char exclusion[] = {'.','!','?','"',' '};  //I actually don't know why this cannot be counted as string aray.

    int letter = 0;
    int sum = 0;

    size_t Elength = sizeof(exclusion);  // use sizeof to culculate the length. Do not use strlen as it only applies to string.

    for (int i = 0, tlen = strlen(text); i < tlen; i++)
    {
        int p = 0;
        while (p < Elength)   //This one took me the longest to figure out. I first used a for loop and I didn't know how to make the loop stop when it finds a char to exclude.
        {   
            if (text[i] != exclusion[p])
            {
                p++;
                letter = 1;  //set value as either 1 or zero instead of having increments
            }
            else 
            {
                letter = 0;
                p = Elength;  //The exiting condition is the most important part
            }
        }

        sum = sum + letter;

    }

    printf("number: %d\n", sum);
}