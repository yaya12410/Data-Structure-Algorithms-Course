#include<iostream>

using namespace std;

void fun(int A[], int n){
    int i;
    A[2] = 4567890;
    for(i = 0; i < n; i++){
        cout<<A[i]<<endl;
    }
}

void fun2(int *p, int n){
    p[2] = 122222222;
    for(int i = 0; i < n; i++){
        cout<<p[i]<<endl;
    }
}

int main()
{
    int arr[5] = {2, 5, 5, 1, 7};
    fun(arr, 5);
    fun2(arr, 5);
}