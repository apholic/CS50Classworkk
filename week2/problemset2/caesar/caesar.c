#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char AL[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char al[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int arc, string argv[]) 
{   
    int key = atoi(argv[1]);
    if (arc != 2)
    {
        printf("\n Usage: ./caesar key:");
        return 1;
    }
    else
    {
        string input = get_string("plaintext: ");
        int l = strlen(input);
        string cipher[l];

        printf("ciphertext: ");
        for (int i = 0; i < l; i++)
        {   
            int num;
            if(islower(input[i]))
            {
                num = ((input[i] - 97) + key) % 26;
                printf("%c", al[num]);
            }
            else if(isupper(input[i]))
            {
                num = ((input[i] - 65) + key) % 26;
                printf("%c", AL[num]);
            }
            else
            {
                printf("%c", input[i]);
            }
            //printf("%d ", num);
        }
        return 0;
    }
    

}