#include<iostream>
#include<stdio.h>

using namespace std;

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i==j)
    {
        m->A[i-1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i==j)
    {
        return m.A[i-1];
    }
    return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for(i=0; i<m.n; i++)
    {
        for(j=0; j<m.n; j++)
        {
            if(i==j)
            {
                printf("%d ", m.A[i]);
            }
            else
            {
                printf("0 ");
            }
            
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("What are the dimensions?\n");
    scanf("%d", &m.n);
    m.A = (int *) malloc(((m.n)*((m.n)-1)/2)*sizeof(int));
    return 0;
}