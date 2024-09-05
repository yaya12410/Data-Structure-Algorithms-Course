#include<iostream>

using namespace std;

class Diagonal
{
private:
    int n;
    int *A;
public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Diagonal()
    {
        delete []A;
    }
};

void Diagonal::Set(int i, int j, int x)
{
    if(i==j)
    {
        A[i-1] = x;
    }
}

int Diagonal::Get(int i, int j)
{
    if(i==j)
    {
        return A[i-1];
    }
    return 0;
}

void Diagonal::Display()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                cout<<A[i]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    
    int i, j, x, dimen;
    cout<<"Enter dimensions ";
    cin>>dimen;
    Diagonal m = {dimen};
    char ch;
    do
    {
        cout<<"Enter your choice: "<<endl<<"1: Create."<<endl<<"2: Get an element."<<endl<<"3: Set an element."<<endl<<"4: Display the matrix."<<endl;
        cin>>ch;
        switch (ch)
        {
        case '1':
            cout<<"Enter the elements of the diagonal: "<<endl;
            for(i=1; i<=dimen; i++)
            {
                // for()
                cin>>x;
                m.Set(i, i, x);
                
            }
            break;
        case '2':
            cout<<endl<<"Enter indices: "<<endl;
            cin>>i>>j;
            if(i==j)
            {
                cout<<m.Get(i, j)<<endl;
            }
            break;
        case '3':
            cout<<"Enter the row,the column and the value of the element at this position: "<<endl;
            cin>>i>>j>>x;
            m.Set(i, j, x);
            break;
        case '4':
            m.Display();
            break;
        default:
            break;
        }
    } while (1);
    
    m.Display();
    return 0;
}