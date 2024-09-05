#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    char temp;
    char x[5] = {'A', 'B', 'C', 'D', 'E'};
    char y[] = {'A', 'B', 'C', 'D', 'E', '\0'};
    char name[] = "JOHN";
    char z[5] = {65, 66, 67, 68, 69};
    char arr[5] = {'A', 'B'};
    temp = 'A';
    printf("%d \n", temp);
    printf("%c \n", temp);
    cout<<temp<<endl;
    cout<<sizeof(temp)<<endl;
    printf("%s\n", name);
    scanf("%s", name);
    printf("%s", name);
    gets(name);
    printf("%s", name);

    return 0;
}