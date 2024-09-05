#include<stdio.h>

int powww(int m, int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n>0)
    {
        return powww(m, n-1)*m;
    }
}

int main()
{
    printf("%d\n", powww(5, 2));
}