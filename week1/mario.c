#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_brick (int i);

int main(void)
{
    int i = get_size();
    print_brick(i);
    
}

//ask user for size
int get_size (void)
{   
    int i;
    do 
    {
        i = get_int ("What is the size? "); //make sure the user has correct input
    }
    while (i < 1);

return i;
}

//print brick
void print_brick (int i) 
{   i = get_size();
    for (int k = 0; k < i; k++) //print out the rows
    {   for (int m = 0; m < i; m++) //print out the colums
        {
            printf("#");
        }
        printf("\n");
    }
}