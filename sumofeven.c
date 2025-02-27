#include<stdio.h>
int even(int lower,int higher)
{
    if(higher<lower)
        return 0;
    if(lower%2==0)
        return lower+even(lower+1,higher);
        else
        return even(lower+1,higher);
}
int main()
{
    printf("%d ",even(2,10));
}
