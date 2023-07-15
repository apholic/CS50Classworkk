#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int selection(int, int number[]);
void swap(int *a, int *b);

//Selection sort: find the smallest unsorted element and add it to the end of the sorted list

int main(void)
{   
    int size = get_int("enter the total number of the list:");
    int number[size];
    for (int i = 0; i < size; i++)
    {   
        /*
        for (int j = 0, l = strlen(number[i]); j < l; j++)
        {
            if (! isdigit(atoi(number[i][j])))
            {
                printf("Please enter a number\n");
                return 1;
            }
        }
        */
        number[i] = get_int("enter number %i:", i + 1);
    }
    int start = 0;
    selection(size, number);
}

int selection(int size, int number[])
{   
    int start = 0;
    for (start = 0; start < size; start++)
    {   
        int min = number[size];     //reset to the last number
        //search the unsorted part of the data to find the smallest value
        for (int j = start; j < size; j++)
        {    
            // problem is that on the second loop, min's number needs to be reset, else the if condition would not be executed.
            if (number[j] < min)
            {
                min = number[j];
            }
        }
    
         // swap the smallest found value with the first element of the unsorted part
        for (int k = 0; k < size; k++)
        {   
            int temp;
            if (number[k] == min)
            {
                temp = number[k];
                number[k] = number[start];
                number[start] = temp;
                printf("%i ", number[start]);
            }
        }
    }
    return number[start];
}