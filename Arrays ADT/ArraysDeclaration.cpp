#include<stdio.h>

int main()
{
    int A[5];
    for(int i = 0; i<5; i++)
    {
        printf("%u \n", &A[i]);
    }
    return 0;
}