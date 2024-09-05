#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Array
{
    int *A;
    int sizee;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0; i<arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

int main()
{
    struct Array arr;
    int n, i;
    printf("Enter the size of your array\n");
    scanf("%d", &arr.sizee);
    arr.A = (int *) malloc(sizeof(int)*arr.sizee);
    arr.length = 0;

    printf("Enter number of numbers:\n");
    scanf("%d", &n);

    printf("Enter all your elements");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    Display(arr);

    return 0;
}
