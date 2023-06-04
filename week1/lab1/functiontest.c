#include <stdio.h>

int subtract(int, int);

int main (void) 
{
    int a = 100;
    int b = 150;
    
    printf("result: %d\n", subtract(a,b));
}

int subtract(int num1, int num2)
{
    return num1 - num2;
}