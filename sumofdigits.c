#include<stdio.h>
int sumofdigits(int n)
{
    if(n==0)
        return 0;
    else{
        int lastdigit=n%10;
        n=n/10;
        return lastdigit+sumofdigits(n);
    }
}
int main()
{
    printf("%d",sumofdigits(234));
}
