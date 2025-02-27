#include<stdio.h>
int rev(int n)
{
    static int res=0,rem;
    if(n>0){
    rem=n%10;
    res=res*10+rem;
    rev(n/10);
    }
    return res;
}
int main()
{    int num=121;
    int x=rev(num);
    if(x==num)
        printf("pandioum");
    else
        printf("not pandioum");
}
