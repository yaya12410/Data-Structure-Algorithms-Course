#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p, *q;
    p = (int *)malloc(5*sizeof(int));
    p[0] = 3;
    p[1] = 1;
    p[2] = 4;
    p[3] = 12;
    p[4] = 14;
    q = (int *)malloc(10*sizeof(int));
    for(int i=0; i<5; i++)
    {
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;
    for(int i=0; i<5; i++)
    {
        printf("%d\n", p[i]);
    }
    return 0;
}