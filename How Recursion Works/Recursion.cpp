#include<iostream>
#include<stdio.h>


using namespace std;


void function(int *num)
{
    if(*num > 0){
        printf("%d\n", *num);
        *num = (*num) - 1;
        function(num);
    }
    
}

int main()
{   
    int x = 5;
    function(&x);
    printf("%d", x);
}