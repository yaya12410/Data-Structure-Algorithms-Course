#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct rect
{
    int length;
    int width;
};

void init(struct rect *r)
{
    cin>>r->length>>r->width;
}

int calcArea(struct rect r)
{
    return ((r.length)*(r.width));
}

int calcPerimeter(struct rect r)
{
    return 2*(r.length + r.width);
}

int main()
{
    struct rect r;
    printf("Enter Length and Width:\n");
    
    init(&r);

    int area = calcArea(r);
    int peri = calcPerimeter(r);

    printf("Area = %d \nPerimeter = %d", area, peri);
    return 0;
}