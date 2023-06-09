#include <cs50.h>
#include <stdio.h>

long get_number(void);
int ndigits(long);
int sdig(int, long);

int main(void)
{
    long number;
    number = get_number();

    int nod;
    nod =  ndigits (number);
    // printf("number of digits: %d \n", nod);

 if (nod == 13 || nod == 15 || nod == 16 )  //the following program only execute if the total number of digtis match the requirement
 {
    // add digits together (even)
    int sumeven = 0;
    int d, q;

    for (d = 2; d < (nod + 1); d = d+2) //include the left most digit
    {
        q = sdig(d, number);
        q = 2 * q;
        if (q>9)
        {
            q = sdig(1, q) + sdig (2, q); //calculate digit again
        }
        // printf("q: %d \n", q);
        sumeven = sumeven + q;
    }
   // printf("sumeven: %d \n", sumeven);

    // add digits together (odd)

    int i2, q2;
    int sumodd = 0;

    for (i2 = 1; i2 < (nod + 1); i2 = i2 + 2)
    {
        q2 = sdig(i2, number);
        sumodd = sumodd + q2;
        // printf("q2: %d \n", q2);
    }
    // printf("sumodd: %d \n", sumodd);

    // calculate the final digit of the sum
    int sum; int D;
    sum = sumeven + sumodd;
    D = sdig (1, sum);
    // printf("digit of final sum: %d \n", D);

    // print out number type
    // get the first and second digit    
    int n1, n2;
    n1 = sdig (nod, number);
    n2 = sdig (nod-1, number);
    
    if (D > 0)
    {
        printf("INVALID\n");
    }
    if (D == 0)
    {
        if (nod == 16)
        {
            if (n1 == 4)
            {
                printf("VISA\n");
            }
            else if (n1 == 5 && (n2 == 1 || n2 == 2 || n2 == 3 || n2 == 4 || n2 == 5))
            {
                printf("MASTERCARD\n");
            }
            else 
            {
                printf("INVALID\n");
            }
        }
        if (nod == 13 && n1 == 4 )
        {
            printf("VISA\n");
        }
        if (nod == 15)
        {   
            if (n1 == 3 && (n2 == 4 || n2 ==7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID \n");
            }
        }
    }
 }

 else {
    printf("INVALID \n");
 }
}

  //get number input

  long get_number(void)
  {
   long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 100000000);  //make sure that the number has enough digit (min:9)
    return number;
  }

//create a function to calculate the number of digits

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

// get any specific digits you want
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