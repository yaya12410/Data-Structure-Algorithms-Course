#include<iostream>

using namespace std;

template<class T>
class Arithametic
{   
private:
    T a;
    T b;
public:
    Arithametic(T a, T b);
    T Add();
    T Sub();
};

template<class T>
Arithametic<T>::Arithametic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
T Arithametic<T>::Add()
{
    return (a + b);
}
template<class T>
T Arithametic<T>::Sub()
{
    return (a - b);
}

int main()
{
    Arithametic<int> ar(10, 5);
    cout<<ar.Add()<<endl;
    Arithametic<float> ar1(1.5, 2.2);
    cout<<ar1.Add()<<endl;
}