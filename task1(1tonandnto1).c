#include<stdio.h>
void callme(int n)
{
    if(n<1)
        return;//give ;after return
        callme(n-1);
        printf("%d ",n);
}

int main()
{
    int n;
    scanf("%d",&n);
    callme(n);

}
