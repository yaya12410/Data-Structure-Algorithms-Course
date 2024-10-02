#include<stdio.h>

void Insert(int A[], int index)
{
    int i=index, temp;
    temp=A[i];

    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int main()
{
    int H[]={0, 2, 5, 8, 9, 4, 10, 7};
    Insert(H, 2);
    return 0;
}