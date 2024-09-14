#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=0;
    q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int value)
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

int dequeue(struct Queue *q)
{
    int deleted=-1;
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

void display(struct Queue *q)
{
    int i=q->front+1;
    do
    {
        printf("%d ", q->Q[i]);
        i=(i+1)%q->size;
    }while(i!=(q->rear+1)%q->size);
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    printf("%d", dequeue(&q));
    return 0;
}