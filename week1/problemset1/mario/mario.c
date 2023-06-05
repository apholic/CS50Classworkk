#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    //print bricks

    int length = height;
    for (int i=0; i < height; i++) //the number of lines to print
    {
        int n_space;
        int n_brick;
        int line = i+1; //denote which line we are printing
        for (n_space = length-line; n_space > 0; n_space--) //the number of spaces per line
        {
            printf(" ");
        }
        for (n_brick = 0; n_brick < line; n_brick++)  //the number of bricks per line
        {
            printf("#");
        }
        printf("  "); //print space in between

        for (n_brick=0; n_brick < line; n_brick++)
        {
             printf("#");
        }

         for (n_space = length-line; n_space > 0; n_space--) //the number of spaces per line
        {
            printf(" ");
        }

        printf("\n");
    }
}
