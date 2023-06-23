#include <stdio.h>
#include <cs50.h>

// prompt: https://www.youtube.com/watch?v=C57wwOOF6ys&list=PLBlnK6fEyqRjoG6aJ4FvFU1tlXbjLBiOP&index=7

/* Previous solution:
int main(void)
{
    int arr[] = {6, 7, 8, 2, 7};
    
    int i, n;
    for(i = 0; i < 4; i++)
    {
        for (n = 1 + i; n < 5; n++)
        {
            if (arr[i] == arr [n])
            {
                printf("output: Yes");
                n = 5;
            }
        }
    }
}
*/

int main(void)
{
    // get user input
    int number = get_int("input:");

    // create a counter ranging from 0~9 to calculate how many times the digit appears in the input
    int seen[10] = {0};

    while(number != 0)
    {   
        int Q = number / 10;
        int rmd = number % 10;
        seen[rmd] = seen[rmd] + 1;     // use remainder and quotient to put the values into the counter
        if (seen[rmd] > 1)
        {
            printf("Output: Yes");
            break;
        }
        if (seen[rmd] <2)
        {
            number = Q;   
        }
    }
    if (number == 0)
    {
        printf("Output: No");       // print output
    }

}

