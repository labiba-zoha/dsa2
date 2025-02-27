#include<stdio.h>
void printeven(int lower,int high)
{
    if(high<lower)
        return;
    if(lower%2==0)
        printf("%d",lower);
    printeven(lower+1,high);
}
int main()
{
    printeven(2,10);
}
