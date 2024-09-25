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
    if(p==NULL)
    {
        return;
    }
    else
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
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

struct Node * rInsert(struct Node *p, int key)
{
    struct Node *t=NULL;
    if(!p)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=NULL;
        t->rchild=NULL;
        return t;
     }
    else if(key<p->data)
    {
        p->lchild=rInsert(p->lchild, key);
    }
    else if(key>p->data)
    {
        p->rchild=rInsert(p->rchild, key);
    }
    return p;
}

struct Node * inPre(struct Node *p)
{
    while(p && p->lchild)
    {
        p=p->lchild;
    }
    return p;
}

struct Node * inSucc(struct Node *p)
{
    while(p && p->rchild)
    {
        p=p->rchild;
    }
    return p;
}

struct Node * delete(struct Node *p, int key)
{
    struct Node *q=NULL;
    if(!p)
    {
        return NULL;
    }
    if(!p->lchild && !p->rchild)
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inPre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild, q->data);
        }
        return NULL;
    }
    if(key<p->data)
    {
        p->lchild=delete(p->lchild, key);
    }
    else if(key>p->data)
    {
        p->rchild=delete(p->rchild, key);
    }
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inPre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild, q->data);
        }
        else if(height(p->lchild)<height(p->rchild))
        {
            q=inSucc(p->rchild);
            p->data=q->data;
            p->rchild=delete(p->rchild, q->data);
        }
        else
        {
            q=inPre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild, q->data);
        }
    }
    return p;
}

int main()
{
    struct Node *found;
    root=rInsert(root, 50);
    rInsert(root, 10);
    rInsert(root, 40);
    rInsert(root, 20);
    rInsert(root, 30);
    delete(root, 50);
    inOrder(root);
    // found=search(20);
    // if(!found)
    // {
    //     printf("\nElement not found");
    // }
    // else
    // {
    //     printf("\nElement %d is found", found->data);
    // }
    return 0;
}