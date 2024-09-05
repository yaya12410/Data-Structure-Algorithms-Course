#include<iostream>

using namespace std;

struct rect {
    int length;
    int width;
};

int area(struct rect &R1){
    R1.length = 10000;
    return R1.length*R1.width;
}

int main()
{
    struct rect R = {10, 50};
    cout<<area(R)<<endl<<R.length<<endl;
    return 0;
}

