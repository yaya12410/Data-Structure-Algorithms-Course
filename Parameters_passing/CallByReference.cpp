#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;

}

// passing parameters by value doesn't swap as the only values being changed are x, y which are temporary parameters

int main()
{
    int a, b;
    a = 10;
    b = 20;
    swap(a, b);
    cout<<a<<endl<<b<<endl;
    return 0;

}