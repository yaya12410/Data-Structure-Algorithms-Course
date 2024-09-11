#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter the size of the stack:\n");
    scanf("%d", &st->size);
    st->top=-1;
    st->S=(int *)malloc(sizeof(int)*st->size);
}

void display(struct Stack *st)
{
    for(int i=st->top; i>=0; i--)
    {
        printf("%d ", st->S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int value)
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

int pop(struct Stack *st)
{
    int deleted=-1;
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

int peek(struct Stack *st, int index)
{
    int value=-1;
    if(st->top-index+1<0)
    {
        printf("Invalid index :(");
    }
    value=st->S[st->top-index+1];
    return value;
}

int isEmpty(struct Stack *st)
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

int stackTop(struct Stack *st)
{
    if(st->top==-1)
    {
        return -1;
    }
    return st->S[st->top];
}

int main()
{
    struct Stack st;
    create(&st);
    
    push(&st, 5);
    push(&st, 10);
    push(&st, 15);
    push(&st, 20);
    push(&st, 25);

    printf("Peeked element: %d\n", peek(&st, 3));

    // printf("Deleted element: %d\n", pop(&st));
    // printf("Deleted element: %d\n", pop(&st));
    // printf("Deleted element: %d\n", pop(&st));
    // printf("Deleted element: %d\n", pop(&st));
    // printf("Deleted element: %d\n", pop(&st));
    // printf("Deleted element: %d\n", pop(&st));

    display(&st);

    return 0;
}