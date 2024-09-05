#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    char A[] = "Python";
    char B[7];
    char C[] = "python";
    int i, j, x, y;
    char temp;
    //first method
    for(i=0; A[i]!='\0'; i++)
    {

    }
    i = i-1;
    for(j=0; i>=0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout<<B<<endl;
    //second method:
    for(x=0; C[x]!='\0'; x++)
    {

    }
    x = x-1;
    for(y=0; y<x; y++, x--)
    {
        temp = C[y];
        C[y] = C[x];
        C[x] = temp;
    }
    printf("%s", C);
    return 0;
}