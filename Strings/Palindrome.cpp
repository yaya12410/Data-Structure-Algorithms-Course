#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    char A[] = "Painter";
    char B[] = "Painting";
    char E[] = "madam";
    char F[7];
    int i, j, x, y;
    for(i=0, j=0; A[i]!='\0' && B[j]!='\0'; i++, j++)
    {
        if(A[i]!=B[j])
        {
            break;
        }
    }
    if(A[i]==B[j])
    {
        printf("Equal");
    }
    else if(A[i]<B[j])
    {
        printf("A is smaller");
    }
    else
    {
        printf("A is greater");
    }

    //Palidromes:
    for(y=0; E[y]!='\0'; y++){

    }
    y = y-1;
    for(x=0; y>=0; x++, y--)
    {
        F[x] = E[y];
    }
    F[x] = '\0';
    printf("\n%s", F);
    return 0;
}