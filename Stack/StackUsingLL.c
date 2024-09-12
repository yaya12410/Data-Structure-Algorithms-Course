#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int pre(char x)
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
    {
        return 0;
    }
    return 1;
}

char *intoPost(char *infix)
{
    int i=0, j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(pre(infix[i])>pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while(top)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="a+b*c-d/e";
    push('#');
    char *postfix=intoPost(infix);

    printf("%s", postfix);
    return 0;
}