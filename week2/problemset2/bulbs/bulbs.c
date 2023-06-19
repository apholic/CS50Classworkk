#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TO DO: Get user input
    string input = get_string("Message: ");

    // Convert string to ASCII numbers
    
    for (int i = 0, l = strlen(input); i < l; i++)
    {   
        int bulb[BITS_IN_BYTE];
        int rmd, n;
        for (n = 0; n < BITS_IN_BYTE; n++)
        {   

            rmd = input [i] % 2;
            input [i] = input [i] / 2;
            bulb[BITS_IN_BYTE - n - 1] = rmd;       //store the value in a new array
        }
        for (int m = 0; m < BITS_IN_BYTE; m++)      //invert the order
        {
            print_bulb(bulb[m]);
        }
        printf("\n");

    }


}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
