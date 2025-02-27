#include<stdio.h>
int floorsqure(int x)
{
    int low=1;
    int high=x;
    int ans=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if((mid*mid)<=x)
        {
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return high;
}
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d",floorsqure(x));
}
