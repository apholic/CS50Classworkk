#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int L = 26;

string encrypt(string, string);

int main(int argc, string argv[]) 
{
    //TODO: Test for invalid key
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    if (argc == 2)
    {   
        int seen[26] = {0};

        for(int i = 0, l = strlen(argv[1]); i < l; i++)
        {
            if (l != L)    //not containing 26 characters
            {
                printf("Error: Key must contain 26 characters.\n");
                return 1;
            }
            if (! isalpha(argv[1][i]))     //containing any character that is not an alphabetic character
            {
                printf("Error: Key must contain 26 characters.\n");
                return 1;
            }
            int count = toupper(argv[1][i]) - 65;      //not containing each letter exactly once
            seen [count] += 1;
            if (seen[count] != 1)
            {
                printf("Error: each letter needs to be unique.\n");
                return 1;
            }
        }
    }
    //TODO: Get input for plaintext
    string plain = get_string("plaintext: ");
    printf("ciphertext: %s\n", encrypt(plain, argv[1]));
    return 0;
}

//TODO: Process text with key
/*
- The key is case-insensitive, but the encrypted message should retain original case
>> Separate conditions for upper case, lower case, and non alphabets.
*/
string encrypt(string plain, string key)
{
    for (int i = 0, l = strlen(plain); i < l; i++)
    {   
        int letter;
        if (islower(plain[i]))
        {
            letter = plain[i] - 97;
            plain[i] = tolower(key[letter]); 
        }
        if (isupper(plain[i]))
        {
            letter = plain[i] - 65;
            plain[i] = toupper(key[letter]);
        }
        if (! isalpha(plain[i]))
        {
            plain[i] = plain [i];
        }
    }
    return plain;

}
