#include<iostream>

using namespace std;

int *fun(int n){
    int *p = (int *)malloc(n * sizeof(int));
    for(int a = 0; a < n; a++){
        p[a] = a+1;
    }
    for(int a = 0; a < n; a++){
        cout<<p[a]<<endl;
    }
    
    return p;
}

int main()
{
    int *A;
    A = fun(5);
    return 0;

}