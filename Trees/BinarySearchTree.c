#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void insert(int key)
{
    struct Node *t=root;
    struct Node *r, *p;
    if(!root)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=NULL;
        p->rchild=NULL;
        root=p;
        return;
    }
    while(t)
    {
        r=t;
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else
        {
            return;
        }
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->lchild=NULL;
    p->rchild=NULL;
    p->data=key;
    if(key<r->data)
    {
        r->lchild=p;
    }
    else
    {
        r->rchild=p;
    }
}

struct Node * search(int key)
{
    struct Node *t=root;
    while(t)
    {
        if(key==t->data)
        {
            return t;
        }
        else if(key<t->data)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    return NULL;
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

int main()
{
    struct Node *found;
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    inOrder(root);
    found=search(20);
    if(!found)
    {
        printf("\nElement not found");
    }
    else
    {
        printf("\nElement %d is found", found->data);
    }
    return 0;
}