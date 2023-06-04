#include <stdio.h>
#include <cs50.h>

// declare functions
int get_start_population(void);
int get_end_population(int sp);
void calculate_years (int sp, int ep);


int main(void)
{
    int sp; int ep;
    sp = get_start_population();
    ep = get_end_population(sp);
    calculate_years (sp, ep);
}


//define funcitons

int get_start_population(void) //prompt for starting population
{
    int startingpop;
    do 
    {
        startingpop = get_int("Starting population size: ");
    }
    while (startingpop < 9);
    return startingpop;
}

int get_end_population (int startingpop) //prompt for ending population
{
    int endingpop;
    do
    {
        endingpop = get_int("Ending population size: ");
    }
    while (endingpop < startingpop);
    return endingpop;
}


void calculate_years(int startingpop, int endingpop) //calculate years it takes to reach ending population
{   
    int years;
    for (years = 0; startingpop < endingpop; years++)
    {
        int growth = startingpop / 3;
        int decade = startingpop / 4;
        startingpop = startingpop + growth - decade;
        //printf("growth: %d\n", growth);
        //printf("decade: %d\n", decade);
    }
   printf("Years: %i\n", years);
    
}