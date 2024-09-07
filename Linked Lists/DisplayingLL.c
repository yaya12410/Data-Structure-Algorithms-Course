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
        printf("%d", p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p)
    {
        RDisplay(p->next);
        printf(" %d", p->data);
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

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    display(first);
    RDisplay(first);
    printf("\n%d", count(first));
    printf("\n%d", RCount(first));
    printf("\n%d", sum(first));
    printf("\n%d", RSum(first));
    
    return 0;
}