#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = get_int("What is the size? ");
    for (int k = 0; k < i; k++)
    {   for (int m = 0; m < i; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}