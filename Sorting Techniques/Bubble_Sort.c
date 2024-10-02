#include<stdio.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void BubbleSort(int Arr[], int num)
{
    int i, j, flag=0;
    for(i=0; i<num-1; i++)
    {
        flag=0;
        for(j=0; j<num-1-i; j++)
        {
            if(Arr[j]>Arr[j+1])
            {
                swap(&Arr[j+1], &Arr[j]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}

void InsertionSort(int Arr[], int num)
{
    int i, j, x;
    for(i=1; i<num; i++)
    {
        j=i-1;
        x=Arr[i];
        while(j>-1 && Arr[j]>x)
        {
            Arr[j+1]=Arr[j];
            j--;
        }
        Arr[j+1]=x;
    }
}

int main()
{
    int Array[]={5, 2, 1, 7, 23, 78, 12};
    int n=7;
    InsertionSort(Array, n);
    for(int i=0; i<n; i++)
    {
        printf("%d ", Array[i]);
    }
    return 0;
}