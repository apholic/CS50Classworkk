#include <cs50.h>
#include <stdio.h>

int sdig(int, long);
int ndigits(long);

int main(void)
{
// test
    int dig;
    int nd = 1;
    long number = 348924;
    dig = sdig(nd, number);
    printf("digit: %d \n", dig);

    int nod;
    nod =  ndigits (number);
    printf("number of digits: %d \n", nod);

  // add digits together (even)
    int sumeven = 0;
    int d, q;

    for (d = 2; d < (nod+1); d = d+2)
    {   
        q = sdig(d, number);
        q = 2 * q;
        if (q>10)
        {
            q = sdig(1, q) + sdig (2, q); //calculate digit again
        }
        printf("q: %d \n", q);
        sumeven = sumeven + q;
    }
    printf("sumeven: %d \n", sumeven);

}

int sdig(int nd, long number)  //nd stands for the desired number of digit
{
    int i, rmd;  // q stands for the quotient
    long ntemp2 = number;
    for (i = 1; i < (nd + 1); i++)
    {   
        rmd = ntemp2 % 10;
        ntemp2 = ntemp2 / 10;   //先计算余数，再替换数字
    }
    return rmd;
}

int ndigits(long number)
{

    int nod;  // Nod stands for the total number of digits containted
    long ntemp = number; 
    for (nod = 0; ntemp > 0; nod++)  
    {
        ntemp = ntemp / 10;  // get the number of digit by dividing the number by 10 each time
    }
    return nod;
}
