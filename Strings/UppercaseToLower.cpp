#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    char A[] = "WELCOME";
    char X[] = "w5LcOMe";
    for(int i=0; A[i]!='\0'; i++)
    {
        A[i] = A[i] + 32;
    }
    cout<<A<<endl;

    for(int i=0; X[i]!='\0'; i++)
    {
        if(X[i]>=65 && X[i]<=90)
        {
            X[i] = X[i] + 32;
        }
        else if(X[i]>=97 && X[i]<=122)
        {
            X[i] = X[i] - 32;
        }
    }
    
    printf("%s", X);
    return 0;
}