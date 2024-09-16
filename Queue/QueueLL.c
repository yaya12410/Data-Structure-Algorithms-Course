#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int value)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Queue is full!");
    }
    else
    {
        t->data=value;
        t->next=NULL;
        if(front==NULL)
        {
            front=t;
            rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int deleted=-1;
    struct Node *t;
    if(front==NULL)
    {
        printf("Queue is empty!");
    }
    else
    {
        deleted=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return deleted;
}

void display()
{
    struct Node *p=front;
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    return 0;
}