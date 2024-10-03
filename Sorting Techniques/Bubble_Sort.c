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

void SelectionSort(int Arr[], int num)
{
    int i, j, k;
    for(i=0; i<num-1; i++)
    {
        for(j=k=i; j<num; j++)
        {
            if(Arr[j]<Arr[k])
            {
                k=j;
            }
        }
        swap(&Arr[i], &Arr[k]);
    }
}

int Partition(int Arr[], int low, int high)
{
    int pivot=Arr[low];
    int i=low, j=high;
    do
    {
        do
        {
            i++;
        }while(Arr[i]<=pivot);
        do
        {
            j--;
        }while(Arr[j]>pivot);
        if(i<j)
        {
            swap(&Arr[i], &Arr[j]);
        }
    }while(i<j);
    swap(&Arr[low], &Arr[j]);
    return j;
}

void QuickSort(int Arr[], int low, int high)
{
    int j;
    if(low<high)
    {
        j=Partition(Arr, low, high);
        QuickSort(Arr, low, j);
        QuickSort(Arr, j+1, high);
    }
}

int main()
{
    int Array[]={11, 13, 7, 12, 16, 9, 24, 5, 10, 3, __INT32_MAX__};
    int n=11;
    QuickSort(Array, 0, 10);
    for(int i=0; i<n; i++)
    {
        printf("%d ", Array[i]);
    }
    return 0;
}