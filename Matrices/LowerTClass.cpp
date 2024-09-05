#include<iostream>

using namespace std;

class Matrix
{
private:
    int *A;
    int n;
public:
    Matrix()
    {
        n = 3;
        A = new int[n*(n+1)/2];
    }
    Matrix(int sz)
    {
        n = sz;
        A = new int[n];
    }
    ~Matrix()
    {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Matrix::Set(int i, int j, int x)
{
    if(i>=j)
    {
        A[(i*(i-1)/2)+j-1] = x;
    }
}

void Matrix::Display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j)
            {
            cout<<A[(i*(i-1)/2)+j-1]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int Matrix::Get(int i, int j)
{
    if(i>=j)
    {
        return A[(i*(i-1)/2)+j-1];
    }
    return 0;
}

int main()
{
    int x, dimen;
    cout<<"Enter dimensions ";
    cin>>dimen;
    Matrix m = {dimen};
    for(int i=1; i<=dimen; i++)
    {
        for(int j=1; j<=dimen; j++)
        {
            cin>>x;
            m.Set(i, j, x);
        }
    }
    cout<<"SIDI YA SIDI"<<endl;
    m.Display();
    return 0;
}