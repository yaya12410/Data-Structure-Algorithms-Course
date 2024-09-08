#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first=NULL;
struct Node *last=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t;
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

void SortedInsert(struct Node *p, int value)
{
    struct Node *t, *q=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;
    if(!p)
    {
        first = t;
    }
    else
    {
        while(p && p->data<value)
        {
            q = p;
            p = p->next;
        }
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int delete(struct Node *p, int pos)
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

int main()
{
    struct Node * f;
    struct Node * y;
    struct Node * t;
    int A[] = {3, 5, 6, 7, 8};
    create(A, 5);
    display(first);
    printf("\n");
    RDisplay(first);
    printf("\n");
    insertLast(first, 9);
    display(first);
    printf("\n%d", count(first));
    printf("\n%d", RCount(first));
    printf("\n%d", sum(first));
    printf("\n%d", RSum(first));
    printf("\n%d", max(first));
    printf("\n%d", RMax(first));
    f = search(first, 9);
    printf("\n%d %d", f, f->data);
    y = RSearch(first, 9);
    printf("\n%d %d", y, y->data);
    // printf("\n%d %d", ImprovedSearch(first, 8), );
    printf("\n");
    SortedInsert(first, 11);
    delete(first, 6);
    display(first);
    printf("\n%d", isSorted(first));
    return 0;
}