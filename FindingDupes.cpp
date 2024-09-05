#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int H[26] = {0};
    char A[] = "finding";
    int i;
    char x;
    for(i=0; A[i]!='\0'; i++)
    {
        H[A[i]-97]++;
    }
    for(int j=0; j<26; j++)
    {
        if(H[j]>1)
        {
            x = j+97;
            cout<<(char) x<<" is repeated more than one time, for exactly "<<H[j]<<" times"<<endl;
        }
        
    }
    return 0;
}