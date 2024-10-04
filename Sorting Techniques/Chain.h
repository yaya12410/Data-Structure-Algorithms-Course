#ifndef Chain_h
#define Chain_h
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first=NULL;
struct Node *second=NULL;
struct Node *third=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for(i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
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
}

void RDisplay(struct Node *p)
{
    if(p)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int RCount(struct Node *p)
{
    static int c = 0;
    if(p)
    {
        return RCount(p->next)+1;
    }
    return c;
}

int sum(struct Node *p)
{
    int total = 0;
    while(p)
    {
        total += p->data;
        p = p->next;
    }
    return total;
}

int RSum(struct Node *p)
{
    if(!p)
    {
        return 0;
    }
    return RSum(p->next)+p->data;
}

int max(struct Node *p)
{
    int max = p->data;
    while(p)
    {
        if(p->data>max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int RMax(struct Node *p)
{
    int x;
    if(!p)
    {
        return 0;
    }
    if(p)
    {
        x = RMax(p->next);
        if(p->data>x)
        {
            return p->data;
        }   
        return x;
    }
}

struct Node * search(struct Node *p, int key)
{
    while(p)
    {
        if(p->data==key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct Node * RSearch(struct Node *p, int key)
{
    if(p)
    {
        if(p->data==key)
        {
            return p;
        }
        return RSearch(p->next, key);
    }
    return NULL;
}

struct Node * ImprovedSearch(struct Node *p, int key)
{
    struct Node *q;
    struct Node *temp;
    while(p)
    {
        if(p->data==key)
        {
            temp = q->next;
            q->next = p->next;
            p->next = first;
            first = temp;
            return first;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    if(!p)
    {
        return NULL;
    }
}

void insert(struct Node *p, int pos, int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    if(pos==0)
    {
        n->next = first;
        n->data = value;
        first = n;
        return;
    }
    for(int i=0; i<pos-1 && p; i++)
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

void insertLast(struct Node *p, int value)
{
    struct Node *last=NULL;
    while(p)
    {
        last=p;
        p=p->next;
    }
    p=first;
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if(!p)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

void SortedInsert(struct Node **H,int x)
{
    struct Node *t,*q=NULL,*p=*H;
    
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    
    if(*H==NULL)
        *H=t;   
    else
    {
    while(p && p->data<x)
    {
        q=p;
        p=p->next;
    }
    if(p==*H)
    {
        t->next=*H;
        *H=t;
    }
    else
    {
        t->next=q->next;
        q->next=t;
    }
    }
}
int dlt(struct Node *p, int pos)
{
    struct Node *q=NULL;
    if(pos<1 || pos>count(p))
    {
        return -1;
    }
    for(int i=0; i<pos-1; i++)
    {
        q = p;
        p = p->next;
    }
    if(p==first)
    {
        struct Node *del=first;
        first = first->next;
        int delete1 = del->data;
        free(del);
        return delete1;
    }
    else
    {
        q->next = p->next;
        int delete2 = p->data;
        free(p);
        return delete2;
    }
}

int isSorted(struct Node *p)
{
    int x = -65536;
    while(p)
    {
        if(p->data<x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

void removeDuplicates(struct Node *p)
{
    struct Node *q=p->next;
    while(q)
    {
        if(p->data==q->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
}

void RecursiveReverseLinks(struct Node *q, struct Node *p)
{
    if(p)
    {
        RecursiveReverseLinks(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void reverseLinks(struct Node *p)
{
    struct Node *q=NULL, *r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void reverseData(struct Node *p)
{
    int numOfNodes = count(p); 
    int i=0;
    int * A = (int *)malloc(numOfNodes*sizeof(int));
    while(p)
    {
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p)
    {
        p->data=A[i];
        p=p->next;
        i--;
    }
}

void concat(struct Node *p, struct Node *q)
{
    third = q;
    while(q->next)
    {
        q=q->next;
    }
    q->next = p;
}

void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        third = p;
        last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = q;
        last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next = p;
            last = last->next;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = last->next;
            q = q->next;
            last->next = NULL;
        }
    }
    while(p)
    {
        last->next = p;
        last = last->next;
        p = p->next;
        last->next = NULL;
    }
    while(q)
    {
        last->next = q;
        last = last->next;
        q = q->next;
        last->next = NULL;
    }
}

int isLooped(struct Node *p)
{
    struct Node *q=first;
    do
    {
        p=p->next;
        q=q->next;
        if(q)
        {
            q=q->next;
        }
        if(p==q)
        {
            return 1;
        }
    }while(p && q && p!=q);
    if(p==q)
    {
        return 1;
    }
    return 0;
}

#endif