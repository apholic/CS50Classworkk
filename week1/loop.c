#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user to enter the number
    int i = get_int("喵呜多少次？");

    //use while loop
    while (i > 0)
    {
        printf("喵呜\n");
        i--;
    }

    //use for loop
    for (int k = get_int("鲨呜多少次？"); k > 0; k--)
    {
        printf("鲨呜\n");
    }
}

