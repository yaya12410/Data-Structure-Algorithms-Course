#include<iostream>

using namespace std;

class Rect
{private:
    int length;
    int width;
public:
Rect(int x, int y){
    length = x;
    width = y;
}

int area(){
    return (length*width);
}

void changeLength(int x){
    length = x;
}
};
int main()
{
    Rect r(1, 55);
    int a = r.area();
    r.changeLength(1);
    
}