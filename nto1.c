#include<stdio.h>
void reverseprint(int n)
{
    if(n<1)
        return;
    printf("%d ",n);
    reverseprint(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    reverseprint(n);
}
