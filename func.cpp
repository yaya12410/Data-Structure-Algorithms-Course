#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Array
{
private:
    int *A;
    int sizee;
    int length;

public:
    Array()
    {
        sizee = 10;
        length = 0;
        A = new int[sizee];
    }
    Array(int sz)
    {
        sizee = sz;
        length = 0;
        A = new int[sizee];
    }
    ~Array()
    {
        delete []A;
    }
    
void Display();
void Swap(int *x, int *y);
void Append(int x);
void Insert(int index, int val);
int Delete(int index);
int Get(int index);
void Set(int val, int index);
int Max();
int Min();
int Sum();
float Avg();
void Reverse();
void SwapReverse();
void InsertSort(int x);
int isSorted();
void ReArrange();
struct Array * Merge(struct Array *arr2);
};
int main()
{
    struct Array arr1 = {10};
    struct Array arr2;
    struct Array *arr3;
    arr1.Insert(0, 14);
    arr1.Display();
    // arr3 = Merge(&arr1, &arr2);
    // Display(*arr3);
    return 0;
}


void Array::Display()
{
    int i;
    // printf("\nElements are\n");
    for(i=0; i<length; i++)
    {
        cout<<A[i]<<endl;
    }
}

void Array::Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Array::Append(int x)
{
    if((length)<sizee){
        A[length++] = x;
    }
}

void Array::Insert(int index, int val)
{
    int i;
    if(index>=0 && index<=length)
    {
        for(i=length; i>index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = val;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = 0;
    int i;
    if(index>=0 && index<(length))
    {
        x = A[index];
        for(i=index; i<length-1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return x;
}

int Array::Get(int index)
{
    if(index<length && index>=0)
    {
        return A[index];
    }
    return -1;
}

void Array::Set(int val, int index)
{
    if(index>=0 && index<length)
    {
        A[index] = val;
    }
}

int Array::Max(){
    int max = A[0];
    for(int i=0; i<length; i++)
    {
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for(int i=0; i<length; i++)
    {
        if(A[i]<min){
            min = A[i];
        }
    }
    return min;
}

int Array::Sum()
{
    int sum = 0;
    for(int i=0; i<length; i++)
    {
        sum += A[i];
    }
    return sum;
}

float Array::Avg()
{
    return (float)Sum()/length;
}

void Array::Reverse()
{
    int *B;
    int temp;
    B = (int *)malloc(length*sizeof(int));
    for(int i=0, j=length-1; j>=0; i++, j--)
    {
        B[i] = A[j];
    }
    for(int i=0; i<length; i++)
    {
        A[i] = B[i];
    }
}

void Array::SwapReverse()
{
    int i, j;
    for(i=0, j=length-1; i<j; i++, j--)
    {
        Swap(&A[i], &A[j]);
    }
}

void Array::InsertSort(int x)
{
    int i = length-1;
    if(length == sizee){
        return;
    }
    while(A[i]>x && i>=0)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;

}

int Array::isSorted()
{
    for(int i=0; i<length-1; i++)
    {
        if(A[i]>A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void Array::ReArrange()
{
    int i, j;
    i = 0;
    j = length-1;
    while(i<j)
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[j]>0)
        {
            j--;
        }
        if(i<j)
        {
            Swap(&A[i], &A[j]);
        }
    }
}

struct Array * Array::Merge(struct Array *arr2)
{
    int i=0, j=0, k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    while(i<length && j<arr2->length)
    {
        if(A[i]<arr2->A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(;i<length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for(;j<arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = length + arr2->length;
    arr3->sizee = 10;
    return arr3;
}