#include<stdio.h>

void fun1(int x)
{
    if(x > 0)
    {
        fun1(x-1);
        printf("%d\n", x);
        
    }
}

//This is an example for a head function

int main()
{
    int x = 3;
    fun1(x);
    return 0;
}