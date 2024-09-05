#include<iostream>
#include<stdio.h>

using namespace std;

int valid(char *ne)
{
    for(int i=0; ne[i]!='\0'; i++)
    {
        if(!(ne[i]>=65 && ne[i]<=90) && !(ne[i]>=97 && ne[i]<=122) && !(ne[i]>=48 && ne[i]<=57))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char *name = "aafASGAWF9";
    printf("%d", valid(name));
    return 0;
}