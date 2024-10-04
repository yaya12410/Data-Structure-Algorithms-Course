#include<stdio.h>
#include"Chain.h"

int hash(int key)
{
    return key%10;
}

void Insert2(struct Node *H[], int key)
{
    int index=hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10];
    for(int i=0; i<10; i++)
    {
        HT[i]=NULL;
    }
    Insert2(HT, 12);
    Insert2(HT, 22);
    Insert2(HT, 32);
    Insert2(HT, 42);
    return 0;
}