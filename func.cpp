#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int sizee;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0; i<arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Append(struct Array *arr, int x)
{
    if((arr->length)<arr->sizee){
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int val)
{
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = val;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if(index>=0 && index<(arr->length))
    {
        x = arr->A[index];
        for(i=index; i<arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return x;
}

int Get(struct Array arr, int index)
{
    if(index<arr.length && index>=0)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int val, int index)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index] = val;
    }
}

int Max(struct Array arr){
    int max = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int sum = 0;
    for(int i=0; i<arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int temp;
    B = (int *)malloc(arr->length*sizeof(int));
    for(int i=0, j=arr->length-1; j>=0; i++, j--)
    {
        B[i] = arr->A[j];
    }
    for(int i=0; i<arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void SwapReverse(struct Array *arr)
{
    int i, j;
    for(i=0, j=arr->length-1; i<j; i++, j--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x)
{
    int i = arr->length-1;
    if(arr->length == arr->sizee){
        return;
    }
    while(arr->A[i]>x && i>=0)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;

}

int isSorted(struct Array arr)
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void ReArrange(struct Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
        {
            i++;
        }
        while(arr->A[j]>0)
        {
            j--;
        }
        if(i<j)
        {
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
}

int main()
{
    struct Array arr = {{2, -1233, 5, 10, -15}, 10, 5};
    InsertSort(&arr, 12);
    ReArrange(&arr);
    Display(arr);
    return 0;
}
