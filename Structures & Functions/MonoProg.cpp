#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int length = 0, width = 0;
    printf("Enter Length and Width:\n");
    cin>>length>>width;

    int area = length*width;
    int peri = 2*(length + width);

    printf("Area = %d \nPerimeter = %d", area, peri);
    return 0;
}