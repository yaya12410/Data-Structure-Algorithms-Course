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
        if(q)
        {
        q->prev=newNode;
        }
        newNode->next=q;
        p->next=newNode;
        newNode->prev=p;
    }
}

int delete(struct Node *p, int index)
{
    int x;
    if(index<1 || index>length(p))
    {
        return -1;
    }
    if(index==1)
    {
        first=first->next;
        if(first)
        {
            first->prev=NULL;
        }
        x=p->data;
        free(p);
        return x;
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            p=p->next;
        }
        if(p->next)
        {
            p->next->prev=p->prev;
            p->prev->next=p->next;
            x= p->data;
            free(p);
        }
        else
        {
            p->prev->next=NULL;
            x=p->data;
            free(p);
        }
        return x;
    }
}

void reverse(struct Node *p)
{
    struct Node *temp;
    while(p)
    {
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        if(!p->prev)
        {
            first=p;
        }
        p=p->prev;
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
    printf("\nDeleted element: %d\n", delete(first, 5));
    printf("\n");
    display(first);
    reverse(first);
    printf("\n");
    display(first);
    return 0;
}