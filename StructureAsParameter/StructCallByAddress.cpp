#include<iostream>

using namespace std;

struct rect {
    int length;
    int width;
};

void changeLength(struct rect *p, int l){
    p->length = l;
}

int main()
{
    struct rect R = {10, 50};
    changeLength(&R, 20);
    cout<<R.length<<endl;
    return 0;
}

