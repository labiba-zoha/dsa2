#include<stdio.h>
void allprintinrange(int low,int upper)
{
    if(low>upper)
        return;
    printf("%d ",low);
    allprintinrange(low+1,upper);
}
int main()
{
 allprintinrange(3 ,8);
}
