#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    char x[] = "hamada";
    int length=0;
    for(int i=0; x[i]!='\0'; i++)
    {
        length = i;
    }
    cout<<length<<endl;
    return 0;
}