#include<stdio.h>
int sum(int n1,int n2)
{
    if(n2==n1)
        return n1;
    else
    {
        return n1+sum(n1+1,n2);
    }
}
int main()
{
    printf("%d",sum(1,10));
}

