#include<stdio.h>

int iFib(int n)
{
    int t0 = 0, t1 = 1, s, i;
    if(n<=1)
    {
        return n;
    }
    else
    {
        for(i=2; i<=n; i++)
        {
            s = t0 + t1;
            t0 = t1;
            t1 = s;
        }
    }
    return s;
}

int recFib(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return recFib(n-2) + recFib(n-1);
    }

}

int F[10];

int memFib(int n)
{
    if(n<=1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
        {
            F[n-2] = memFib(n-2);
        }
        if(F[n-1]==-1)
        {
            F[n-1] = memFib(n-1);
        }
        return F[n-2] + F[n-1];
    }
}

int main()
{
    for(int i = 0; i<10; i++)
    {
        F[i] = -1;
    }
    printf("%d\n", memFib(6));

    return 0;
}