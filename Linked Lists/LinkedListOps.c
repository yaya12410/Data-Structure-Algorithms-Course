#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first=NULL;

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

int main()
{
    struct Node * f;
    struct Node * y;
    int A[] = {3, 5, 77, 10, 15};
    create(A, 5);
    display(first);
    printf("\n");
    RDisplay(first);
    printf("\n%d", count(first));
    printf("\n%d", RCount(first));
    printf("\n%d", sum(first));
    printf("\n%d", RSum(first));
    printf("\n%d", max(first));
    printf("\n%d", RMax(first));
    f = search(first, 10);
    printf("\n%d %d", f, f->data);
    y = RSearch(first, 10);
    printf("\n%d %d", y, y->data);
    
    return 0;
}