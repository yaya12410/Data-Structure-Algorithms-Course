#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    char A[] = "How are   you";
    int vcount=0;
    int ccount=0;
    int wcount=1;
    for(int i=0; A[i]!='\0'; i++)
    {
        if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u' || A[i]=='A' || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U')
        {
            vcount++;
        }
        else if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122))
        {
            ccount++;
        }
    }
    for(int i=0; A[i]!='\0'; i++)
    {
        if(A[i]==' ' && A[i-1]!=' ')
        {
            wcount++;
        }
    }
    printf("%d\n", vcount);
    printf("%d\n", ccount);
    printf("%d", wcount);
    return 0;
}