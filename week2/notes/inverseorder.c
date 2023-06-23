#include <stdio.h>

int main(void)
{   
    int N = 9;
    int arr[] = {34, 56, 54, 32, 67, 89, 90, 32, 21};
    
    for(int i = 0; i < N; i++)
    {
        printf("%d ", arr[N - i - 1]);
    }
    printf("\n");
}