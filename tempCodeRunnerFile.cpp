include<stdio.h>
#include<stdlib.h>

using namespace std;

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
