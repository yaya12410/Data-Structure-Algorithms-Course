#include<iostream>

using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term * t;
};

void Create(struct Poly *p)
{
    int i;
    cout<<"Enter the number of terms: ";
    cin>>p->n;
    p->t = new Term[p->n];
    for(i=0; i<p->n; i++)
    {
        cout<<"Enter the coefficient of term "<<i<<" ";
        cin>>p->t[i].coeff;
        cout<<"Enter the exponent of term "<<i<<" ";
        cin>>p->t[i].exp;
    }
}

void display(struct Poly p)
{
    int i;
    for(i=0; i<p.n; i++)
    {
        cout<<p.t[i].coeff<<"x"<<p.t[i].exp;
        if(i!=p.n-1)
        {
            cout<<"+";
        }
    }
    cout<<endl;
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i=0, j=0, k=0;
    struct Poly *sum;
    sum = new Poly;
    sum->t = new Term[(p1->n)+(p2->n)];

    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].exp>p2->t[j].exp)
        {
            sum->t[k++] = p1->t[i++];
        }
        if(p1->t[i].exp<p2->t[j].exp)
        {
            sum->t[k++] = p2->t[j++];
        }
        else
        {
            sum->t[k] = p1->t[i++];
            sum->t[k++].coeff += p2->t[j++].coeff;
        }
    }
    for(;i<p1->n;i++)
    {
        sum->t[k++] = p1->t[i];
    }
    for(;j<p2->n;j++)
    {
        sum->t[k++] = p2->t[j];
    }
    sum->n = k;
    return sum;
}

int main()
{
    struct Poly p1, p2, *p3;
    Create(&p1);
    Create(&p2);
    p3 = add(&p1, &p2);
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    display(*p3);

    return 0;
}