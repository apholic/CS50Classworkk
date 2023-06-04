#include <stdio.h>
#include <cs50.h>

// declare functions
int get_start_population(void);
int get_end_population(int sp);
int calculate_years (int ep, int sp);


int main(void)
{
    int sp; int ep; int y;
    sp = get_start_population();
    ep = get_end_population(sp);
    y = calculate_years (sp, ep);
    printf("Years: %i\n", y);
}


//define funcitons

int get_start_population(void) //prompt for starting population
{
    int sp;
    do 
    {
        sp = get_int("Starting population size: ");
    }
    while (sp < 9);
    return sp;
}

int get_end_population (int sp) //prompt for ending population
{
    int ep;
    do
    {
        ep = get_int("Ending population size: ");
    }
    while (ep < sp);
    return ep;
}


int calculate_years(int ep, int sp) //calculate years it takes to reach ending population
{   
    int y;
    for (y = 0; sp < ep; y++)
    {
        int growth = sp / 3;
        int decade = sp / 4;
        sp = sp + growth - decade;
    }
    return y;
    
}