#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"Stack.h"

struct Node *root=NULL;

void Create()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Enter root value: ");
    scanf("%d", &x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->lchild=t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->rchild=t;
            enqueue(&q, t);
        }
    }
}

void preOrder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void postOrder(struct Node *p)
{
    if(p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}
void inOrder(struct Node *p)
{
    if(p)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

void iPreOrder(struct Node *p)
{
    struct Stack stk;
    stackCc(&stk, 100);
    while(p || !isEmptyStack(&stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void levelOrder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", p->data);
    enqueue(&q, p);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        if(p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}

int count(struct Node *p)
{
    if(p)
    {
        return count(p->lchild)+count(p->rchild)+1;
    }
    return 0;
}

int height(struct Node * p)
{
    int x=0, y=0;
    if(p==0)
    {
        return 0;
    }
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
}

int main()
{
    Create();
    printf("count is %d ", count(root));
    printf("height is %d ", height(root));
    return 0;
}