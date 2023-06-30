#include <cs50.h>
#include <stdio.h>
#include <string.h>

// this is notes for figuring out command line argument and string
// also struggled with imcompatible types.

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }

    int i = 0;
    while (argv[i] != '\0')
    {
        i++;
        printf("%d", i);
        printf("%s", argv[i]);
    }
    //int l = strlen(argv);
    printf("%d\n",argc);
}