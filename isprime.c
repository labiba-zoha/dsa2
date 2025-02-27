#include<stdio.h>
int isprime(int num,int dis)
{
    if(num<=2)
    {
        if(num==2)
            return 1;
        else
            return 0;
    }
    if(num%dis==0)
    {
        return 0;//not prime
    }
    if(dis*dis>num)//dis=i,i*i>num
       return 1;//prime number
    return isprime(num,dis+1);
}
int main()
{
    int num;
    scanf("%d",&num);
    if(isprime(num,2))
        printf(" the number is prime %d",num);

    else
    {
        printf("%d is not prime",num);
    }
}
