#include<iostream>

using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

}

//Same as the call by value code, the only difference is that we pass the address so the function should receive a pointer 

int main()
{
    int a, b;
    a = 10;
    b = 20;
    swap(&a, &b);
    cout<<a<<endl<<b<<endl;
    return 0;

}