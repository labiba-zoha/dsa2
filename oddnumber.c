#include<stdio.h>
void oddnumber(int lower,int upper)
{
    if(lower>upper)
        return;
    printf("%d ",lower);
    oddnumber(lower+2,upper);
}
int main()
{
    oddnumber(1,5);
}
