#include<iostream>

using namespace std;

struct rect{
    int length;
    int width;
};

void initialize(struct rect *r, int x, int y){
    r->length = x;
    r->width = y;
}

int area(struct rect r){
    return ((r.length)*(r.width));
}

void changeLength(struct rect *r, int x){
    r->length = x;
}

int main()
{
    struct rect r;
    initialize(&r, 44, 55);
    int a = area(r);
    changeLength(&r, 1);
    cout<<r.length<<endl<<r.width<<endl<<a<<endl;
}