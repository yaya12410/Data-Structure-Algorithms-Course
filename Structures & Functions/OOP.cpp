#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class rect
{private:

    int length;
    int width;

public:

rect()
{
    cin>>length>>width;
}

int calcArea()
{
    return ((length)*(width));
}

int calcPerimeter()
{
    return 2*(length + width);
}
};
int main()
{   
    
    printf("Enter Length and Width:\n");
    rect r;
    
    int area = r.calcArea();
    int peri = r.calcPerimeter();

    printf("Area = %d \nPerimeter = %d", area, peri);
    return 0;
}