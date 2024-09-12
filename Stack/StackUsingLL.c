#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char value)
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

char pop()
{
    struct Node *p=top;
    if(!top)
    {
        printf("Stack UNDERFLOW");
        return -1;
    }
    else
    {
        char deleted=top->data;
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

int isBalanced(char *exp)
{
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(top==NULL)
            {
                return 0;
            }
            
            pop();
        }
    }
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp="((a+b)*(c-d)))";
    printf("%d", isBalanced(exp));
    return 0;
}