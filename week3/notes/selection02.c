#include <cs50.h>
#include <stdio.h>

void selection(int size, int number[]);
void swap(int *a, int *b);

int main(void)
{
    int size = get_int("Total number: ");
    int number[size];
    for (int i = 0; i < size; i++)
    {
        number[i] = get_int("Enter number %i: ", i + 1);
    }
    selection(size, number);
}

void selection(int size, int number[])
{
    for (int j = 0; j < size; j++)
    {
        int *indexmin = &number[j];
        for (int i = j; i < size; i++)
        {
            if (number[i] < *indexmin)
            {
                swap(indexmin, &number[i]);
            }    
        }
        printf("%i ", *indexmin);
    }
    
}

void swap(int *a, int *b)  //swap the pointee
{
    int temp = *a;
    *a = *b;
    *b = temp;
}