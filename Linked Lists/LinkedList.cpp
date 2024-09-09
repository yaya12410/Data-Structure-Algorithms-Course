#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList()
    {
        first = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int value);
    int Delete(int index);
    int length();
};

LinkedList::LinkedList(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i=1; i<n; i++)
    {
        t=new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while(first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void LinkedList::Insert(int index, int value)
{
    Node *n = new Node;
    Node *p = first;
    Node *temp;
    if(index==0)
    {
        n->next = first;
        n->data = value;
        first = n;
        return;
    }
    for(int i=0; i<index-1 && p; i++)
    {
        if(p)
        {
        p = p->next;
        }
    }
    if(p)
    {
    n->next = p->next;
    p->next = n;
    n->data = value;
    }
}

int LinkedList::Delete(int index)
{
    Node *q=NULL;
    Node *p=first;
    if(index<1 || index>length())
    {
        return -1;
    }
    for(int i=0; i<index-1; i++)
    {
        q = p;
        p = p->next;
    }
    if(p==first)
    {
        Node *del=first;
        first = first->next;
        int delete1 = del->data;
        delete (del);
        return delete1;
    }
    else
    {
        q->next = p->next;
        int delete2 = p->data;
        delete (p);
        return delete2;
    }
}

int LinkedList::length()
{
    Node *p=first;
    int c=0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList list1(A, 5);
    list1.Display();
    list1.Insert(4, 99);
    cout<<endl;
    list1.Display();
    list1.Delete(2);
    cout<<endl;
    list1.Display();
    return 0;
}