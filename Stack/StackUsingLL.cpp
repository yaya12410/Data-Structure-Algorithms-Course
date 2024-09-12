#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
public:
    Stack()
    {
        top=NULL;
    }
    void push(int value);
    int pop();
    void display();
};

void Stack::push(int value)
{
    Node *temp=new Node;
    if(temp)
    {
        temp->data=value;
        temp->next=top;
        top=temp;
    }
    else
    {
        cout<<"Stack OVERFLOW!";
    }
}

int Stack::pop()
{
    if(!top)
    {
        cout<<"Stack UNDERFLOW!";
        return -1;
    }
    else
    {
        Node *temp=top;
        top=top->next;
        int deleted=temp->data;
        delete temp;
        return deleted;
    }
}

void Stack::display()
{
    Node *temp=top;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Stack st;
    st.push(20);
    st.push(40);
    st.push(60);
    st.push(80);
    st.display();
    cout<<st.pop()<<endl;
    st.display();
    return 0;
}