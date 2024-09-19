#include<stdio.h>
#include<stdlib.h>
#ifndef Stack_h
#define Stack_h


struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void stackCc(struct Stack *st, int mysize)
{
    st->size=mysize;
    st->top=-1;
    st->S=(struct Node **)malloc((sizeof(struct Node *))*st->size);
}

void push(struct Stack *st, struct Node * value)
{
    if(st->top==st->size-1)
    {
        printf("Stack OVERFLOW\n");
    }
    else
    {
        st->top++;
        st->S[st->top]=value;
    }
}

struct Node * pop(struct Stack *st)
{
    struct Node * deleted=NULL;
    if(st->top==-1)
    {
        printf("Stack UNDERFLOW\n");
    }
    else
    {
        deleted=st->S[st->top];
        st->top--;
    }
    return deleted;
}

int isEmptyStack(struct Stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *st)
{
    if(st->top==st->size-1)
    {
        return 1;
    }
    return 0;
}

struct Node * stackTop(struct Stack *st)
{
    if(st->top==-1)
    {
        return NULL;
    }
    return st->S[st->top];
}
#endif