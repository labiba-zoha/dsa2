#include<stdio.h>
int binary(int a[],int low,int high,int key,int n){
//bubble sort
for(int i=0; i<n-1; i++)
{
    for(int j=0; j<n-1-i; j++)
    {
        if(a[j]>a[j+1])
        {
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}







if(low>high)
    return -1;
int mid=(low+high)/2;
if(a[mid]==key)
{
    return mid;
}
else if(a[mid]>key)
{
    return binary(a,low,mid-1,key,n);
}
else
    return binary(a,mid+1,high,key,n);
}
int main()
{
    int n;
    printf("enter the number of elmets");
    scanf ("%d",&n);
    int a[n];
    printf("enter the array elemts");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int key;
    scanf("%d",&key);

    int flag=binary(a,0,n-1,key,n);
    if(flag==-1)
    {
        printf("not found");
    }
    else
    {
        printf("found at indesx%d",flag);
    }
}
