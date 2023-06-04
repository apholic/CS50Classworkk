#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt for starting population
    int sp;
    do
    {
        sp = get_int("What is the starting population? ");
    }
    while (sp < 9);

    //prompt for ending population
    int ep;
    do
    {
        ep = get_int("What is the ending population? ");
    }
    while (ep < sp);

    //calculate years
    int y;
    for (y=0; sp < ep; y++)
    {
        sp = sp + (sp / 3) - (sp / 4);
    }

    //print years
    printf("Years: %d\n", y);
}