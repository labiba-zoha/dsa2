#include<stdio.h>
int Maxcross(int arr[],int p,int q,int r)
{
    int leftsum=-99,sum=0;
    for(int i=q;i>=p;i--)
    {
        sum=sum+arr[i];
        if(sum>leftsum)
            leftsum=sum;
    }
    int rightsum=-99;
    sum=0;
    for(int j=q+1;j<=r;j++)
    {
        sum=sum+arr[j];
        if(sum>rightsum)
            rightsum=sum;
    }
    return leftsum+rightsum;


}
int Maxsubarray(int arr[],int p,int r)
{
    if(p==r)//one elemnt
        return arr[p];
    int q=(p+r)/2;
    int leftmss=Maxsubarray(arr,p,q);
    int righrmss=Maxsubarray(arr,q+1,r);
    int cross=Maxcross(arr,p,q,r);
}
int main()
{
   int n;

   printf("enter the number of elmets");
   scanf("%d",&n);
   int arr[n];
    printf("enter the array elemts");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("the maxium sum is %d ",Maxsubarray(arr,0,n-1));


}
