#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i;
    do 
    {
        i = get_int("What is the size? ");    
    }
   while (i < 0); //make sure that the user have correct input

    for (int k = 0; k < i; k++) //print out the rows
    {   for (int m = 0; m < i; m++) //print out the colums
        {
            printf("#");
        }
        printf("\n");
    }
}