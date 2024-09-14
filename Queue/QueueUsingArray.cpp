#include<iostream>

using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    Queue()
    {
        front=-1;
        rear=-1;
        size=10;
        Q=new int[size];
    }
    Queue(int size)
    {
        front=-1;
        rear=-1;
        this->size=size;
        Q=new int[this->size];
    }
    void enqueue(int value);
    int dequeue();
    void display();
};

void Queue::enqueue(int value)
{
    if(rear==size-1)
    {
        cout<<"Queue is full!"<<endl;
    }
    else
    {
        rear++;
        Q[rear]=value;
    }
}

int Queue::dequeue()
{
    int deleted=-1;
    if(front==rear)
    {
        cout<<"Queue is empty!"<<endl;
    }
    else
    {
        deleted=Q[front+1];
        front++;
    }
    return deleted;
}

void Queue::display()
{
    for(int i=front+1; i<=rear; i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}