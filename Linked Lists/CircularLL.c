#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int Array[], int arrayLength)
{
    int i;
    struct Node *t, *last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data = Array[0];
    Head->next = Head;
    last = Head;
    for(i=1; i<arrayLength; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = Array[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h=h->next;
    }while(h!=Head);
    printf("\n");
}

void RDisplay(struct Node *h)
{
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void insert(struct Node *h, int index, int value)
{
    struct Node *t=Head;
    if(index<0 || index>Length(h))
    {
        return;
    }
    if(index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        if(!Head)
        {
            Head=t;
            Head->next=Head;
        }
        else
        {
            while(h->next!=Head)
            {
                h=h->next;
            }
            h->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            h=h->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=value;
        t->next=h->next;
        h->next=t;
    }
}

int main()
{
    int Array[] = {2, 3, 4, 5, 6};
    create(Array, 5);
    RDisplay(Head);

    insert(Head, 5, 10);
    printf("\n");
    display(Head);
    return 0;
}