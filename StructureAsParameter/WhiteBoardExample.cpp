#include<iostream>

using namespace std;

struct test
{
    int A[5];
    int n;
};

void fun(struct test *t1)
{
    t1->A[0] = 10;
    t1->A[1] = 9;
    t1->A[2] = 8;

}

int main()
{
    struct test t = {{2, 4, 6, 8, 10}, 5};
    fun(&t);
    cout<<t.A[0]<<endl<<t.n<<endl;
    return 0;
}

