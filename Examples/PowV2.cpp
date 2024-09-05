#include<stdio.h>

int powerr(int m, int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        return powerr(m*m, n/2);
    }
    else
    {
        return m*powerr(m*m, (n-1)/2);
    }
}

int main()
{
    printf("%d\n", powerr(6, 3));
}