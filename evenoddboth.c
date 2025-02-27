#include<stdio.h>//low print functioncall befor print upper function call after
void evenodd(int lower,int higher)
{
    if(higher<lower)
        return;
    printf("%d",lower);
    evenodd(lower+2,higher);
}
int main()
{
    evenodd(1,10);
}
