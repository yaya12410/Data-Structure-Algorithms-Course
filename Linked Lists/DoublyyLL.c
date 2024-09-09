#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void insert(struct Node *p, int index, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q;
    if(index==0)
    {
        newNode->data=value;
        p->prev=newNode;    
        newNode->prev=NULL;
        newNode->next=p;
        first=newNode;
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            p=p->next;
        }
        newNode->data=value;
        q=p->next;
        q->prev=newNode;
        newNode->next=q;
        p->next=newNode;
        newNode->prev=p;
    }
}

int main()
{
    int A[]={1, 2, 3, 4, 5};
    create(A, 5);
    printf("Here is length %d", length(first));
    printf("\n");
    insert(first, 4, 123);
    display(first);
    return 0;
}