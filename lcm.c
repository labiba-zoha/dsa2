#include<stdio.h>
int gcd(int x,int y)
{
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}
int lcm(int x,int y)
{
    return (x*y)/gcd(x,y);
}
int main()
{
    int a=3,b=2;
    if(a>b)
        printf("%d",lcm(a,b));
    else
    {
        printf("%d",lcm(b,a));
    }

}

