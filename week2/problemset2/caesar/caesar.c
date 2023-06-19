#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) 
{   
    if ((argc != 2 ))
    {
        printf("Usage: ./caesar key: ");
        return 1;
    }
    if ((argc == 2) && isdigit(atoi(argv[1])))
    { 
        string input = get_string("plaintext: ");
        int key = atoi(argv[1]); 
        int l = strlen(input);
        string cipher[l];

        for (int i = 0; i < l; i++)
        {
            input[i] = (input[i] + key) % 26;
        }
        printf("%s", input);
        return 0;
    }
}