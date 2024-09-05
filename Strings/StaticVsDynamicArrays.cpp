#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[5];
    int *p;
    // p = new int[5];
    p = (int *) malloc(5* sizeof(int));
    p[0] = 4;
    p[1] = 5;
    p[2] = 6;

    for(int i = 0; i<5; i++)
    {
        printf("%d \n", p[i]);
    }

    free(p);
    
    for(int i = 0; i<5; i++)
    {
        printf("%d \n", p[i]);
    }

    return 0;
}