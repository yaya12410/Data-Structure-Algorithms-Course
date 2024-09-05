#include<stdio.h>

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;   
    }
}

int c1(int n, int r)
{
    int t1 = fact(n), t2 = fact(r), t3 = fact(n-r);
    return (t1)/(t2*t3);
}

int c2(int n, int r)
{
    if(r==0 || r==n)
    {
        return 1;
    }
    else
    {
        return c2(n-1, r-1) + c2(n-1, r);
    }
}

int main()
{
    printf("%d", c2(5, 2));  
    return 0;
}