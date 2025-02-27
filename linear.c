#include<stdio.h>
int liner(int a[],int i,int n,int key)
{
    if(i>=n)
        return -1;
    if(a[i]==key)
        return i;
    else
        return liner(a,i+1,n,key);
}
int main()
{ int n;
 scanf ("%d",&n);
 int a[n];
 for(int i=0;i<n;i++)
 {
     scanf("%d",&a[i]);
 }
    int key;
    scanf("%d",&key);

    int flag=liner(a,0,n,key);
    if(flag==-1)
    {
        printf("not found");
    }
    else
    {
        printf("found at indesx%d",flag);
    }
}

