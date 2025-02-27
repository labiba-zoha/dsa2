#include<stdio.h>
int countdigits(int n)
{
    if(n==0)
        return 0;
    else{
        n=n/10;
        return 1+countdigits(n);
    }
}
int main()
{
    printf("%d",countdigits(234));
}

