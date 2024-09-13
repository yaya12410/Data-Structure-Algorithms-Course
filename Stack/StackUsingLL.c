#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}

int outStackPre(char x)
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 3;
    }
    else if(x=='(')
    {
        return 7;
    }
    
    else if(x=='^')
    {
        return 6;
    }
    return 0;
}

int stackPre(char x)
{
    if(x=='+' || x=='-')
    {
        return 2;
    }
    else if(x=='*' || x=='/')
    {
        return 4;
    }
    else if(x=='(')
    {
        return 0;
    }
    else if(x=='^')
    {
        return 5;
    }
    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')' || x=='^')
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
    postfix=(char *)malloc((len+3)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i])!=0)
        {
            postfix[j++]=infix[i++];
            continue;
        }
        else if(isEmpty())
        {
            push(infix[i++]);
        }
        else
        {
            if(outStackPre(infix[i])>stackPre(top->data))
            {
                push(infix[i++]);
            }
            else if(outStackPre(infix[i])==stackPre(top->data))
            {
                i++;
                pop();
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

int Eval(char *postfix)
{
    int i=0, x1, x2, result;
    for(i; postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=pop();
            x1=pop();
            switch (postfix[i])
            {
            case '+':
                result=x1+x2;
                break;
            case '-':
                result=x1-x2;
                break;
            case '*':
                result=x1*x2;
                break;
            case '/':
                result=x1/x2;
                break;
            default:
                break;
            }
            push(result);
        }
    }
    return(top->data);
}

int main()
{
    char *postfix="234*+82/-";
    

    printf("%d", Eval(postfix));
    return 0;
}