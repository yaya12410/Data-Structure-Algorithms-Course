#include<stdio.h>

double e(int x, int n)
{
    static double p=1, f=1;
    double r;
    if(n==0)
    {
        return 1;
    }
    else
    {
        r = e(x, n-1);
        p=p*x;
        f=f*n;
        return r+p/f;   
    }
    
}

int main()
{
    float x = e(1, 10);
    printf("%.10lf \n", x);
    return 0;
}