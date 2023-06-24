#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

string rotate(int key, string input);

int main(int arc, string argv[]) 
{   
    if (arc != 2)
    {
        printf("Usage: ./caesar key:");
        return 1;
    }
    else if (arc == 2)
    {
        for (int ia = 0, la = strlen(argv[1]); ia < la; ia ++)
        {
            if (! isdigit(
                argv[1][ia]))                 // my previous problem was that I didn't know we can zoom in the index by adding another bracket...
            {
                printf("Usage: ./caesar key:");
                return 1;
            }
        }

        string input = get_string("plaintext: ");
        int l = strlen(input);
        int key = atoi(argv[1]);
        printf("ciphertext: %s\n", rotate(key, input));
        return 0;
    }
}

string rotate(int key, string input)
{
    int l = strlen(input);
    for (int i = 0; i < l; i++)
    {   
        if (islower(input[i]))
        {
            input[i] = ((input[i] - 97) + key) % 26 + 97;
        }
        else if (isupper(input[i]))
        {
            input[i] = ((input[i] - 65) + key) % 26 + 65;
        }
        else
        {
            input[i] = input[i];
        }
        //printf("%d ", num);
    }
    return input;
}