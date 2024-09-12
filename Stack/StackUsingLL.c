#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(!n)
    {
        printf("Stack OVERFLOW!");
    }
    else
    {    
        n->data=value;
        n->next=top;
        top=n;
    }
}

int pop()
{
    struct Node *p=top;
    if(!top)
    {
        printf("Stack UNDERFLOW");
        return -1;
    }
    else
    {
        int deleted=top->data;
        top=top->next;
        free(p);
        return deleted;
    }
}

void display()
{
    struct Node *p=top;
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    push(5);
    push(51);
    push(52);
    push(53);
    push(54);
    push(55);
    display();
    printf("\n");
    pop();
    pop();
    display();
    return 0;
}