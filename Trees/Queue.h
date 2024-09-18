#ifndef Queue_h
#define Queue_h
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=0;
    q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *value)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Queue is full!");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=value;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node * deleted=NULL;
    if(q->front==q->rear)
    {
        printf("Queue is empty!");
    }
    else
    {
        q->front=(q->front+1)%q->size;
        deleted=q->Q[q->front];
    }
    return deleted;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

#endif