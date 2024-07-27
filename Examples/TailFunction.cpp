#include<stdio.h>

void fun1(int x)
{
    if(x > 0)
    {
        printf("%d\n", x);
        fun1(x-1);
    }
}

//This is an example for a tail function

int main()
{
    int x = 3;
    fun1(x);
    return 0;
}