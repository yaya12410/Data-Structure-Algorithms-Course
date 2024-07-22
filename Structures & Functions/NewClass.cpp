#include<iostream>
#include<stdio.h>

using namespace std;

class rect
{private:
    int length;
    int width;

public:
    rect(){
        length = 1, width = 1;
    }
    rect(int a, int b);
    int calcArea();
    int calcPeri();
    int getLength(){return length;}
    void setLength(int l){length = l;}
    void setWidth(int w){width = w;}
};
rect::rect(int a, int b)
{
    length = a;
    width = b;
}
int rect::calcArea()
{
    return(length*width);
}
int rect::calcPeri()
{
    return(2*(length + width));
}

int main()
{
    rect r(10, 5);
    cout<<r.calcArea();
    cout<<endl<<r.calcPeri()<<endl;
    r.setLength(4);
    r.setWidth(4);
    
    cout<<r.calcArea();
    cout<<endl<<r.calcPeri();


}