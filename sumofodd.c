#include<stdio.h>
int oddsum(int low,int high)
{
    if(high<low)
        return 0;
    return low+oddsum(low+2,high);
}
int main()
{
    printf("%d",oddsum(1,5));
}
