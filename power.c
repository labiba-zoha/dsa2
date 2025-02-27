#include<stdio.h>
float power(float x ,int y)
{
    float temp;
    if(y==0)
        return 1;
     temp=power(x,y/2);//divide and conquew toether
    if(y%2==0)
    {
        return temp*temp;
    }
    else{
        if(y>0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}
int main()
{
    float x=4;
    int n=3;
    printf("%f",power(x,n));
}
