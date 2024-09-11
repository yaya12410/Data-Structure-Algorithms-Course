#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

void create()
{
    struct Node *t, *last;
    int num;
    printf("Enter the number of terms:\n");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp:\n");
    for(int i=0; i<num; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next=NULL;
        if(!poly)
        {
            poly=t;
            last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    create();
    display(poly);
    return 0;
}