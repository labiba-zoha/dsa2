#include<stdio.h>
int main()
{
    char name[50];
    gets(name);
    int lenth=strlen(name);
    reverseDisplay(name,lenth-1);
    printf("\n");
    Display(name,lenth-1);
}
void reverseDisplay(char str[],int index)
{
    if(index<0)
        return;
    printf("%c",str[index]);
    reverseDisplay(str,index-1);
}
void Display(char str[],int index)
{
    if(index<0)
        return;

    Display(str,index-1);
    printf("%c",str[index]);
}

