#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}

int balanceFactor(struct Node *p)
{
    int hl, hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl;
    struct Node *plr;
    pl=p->lchild;
    plr=p->lchild->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p)
    {
        root=pl;
    }
    return pl;
}

struct Node * rInsert(struct Node *p, int key)
{
    struct Node *t=NULL;
    if(!p)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->height=1;
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
    
    p->height=NodeHeight(p);

    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
    {
        return LLRotation(p);
    }
    else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1)
    {
        // return LRRotation(p);
    }

    return p;
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

int main()
{
    root=rInsert(root, 10);
    rInsert(root, 5);
    rInsert(root, 2);
    inOrder(root);
    return 0;
}