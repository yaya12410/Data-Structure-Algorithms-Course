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

int main()
{
    int Array[] = {2, 3, 4, 5, 6};
    create(Array, 5);
    RDisplay(Head);
    return 0;
}