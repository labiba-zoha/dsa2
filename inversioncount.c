
#include<stdio.h>
int  inversioncount(int arr[],int l,int r)
{     int res=0;
    if(l<r)//l<r means one elmet
    {
        int mid=(l+r)/2;
        res=res+inversioncount(arr,l,mid);
        res=res+inversioncount(arr,mid+1,r);
         res=res+mergeandcount(arr,l,mid,r);
    }
    return res;
}
int mergeandcount(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int arr1[n1];
    //left subarray
    int arr2[n2];
    //right sub arrau
    for(int i=0;i<n1;i++)
    {
        arr1[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        arr2[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=l,  res=0;
    while(i<n1&&j<n2)
    {
        if(arr1[i]<=arr2[j])//ascding deceding >=
        {
            arr[k]=arr1[i];
            i++;

        }
        else
        {
            arr[k]=arr2[j];//inversion happens when a[j]>a[i]
            j++;
            res=res+(n1-i);
        }
        k++;
    }
    while(i<n1)//j findjes so copy all numbers of n1
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
    return res;






}
int main()
{
  int n;
  scanf("%d",&n);
  int arr[100];

  for(int i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  //mergesort(arr,0,n-1);
  //array,left index,right index

  printf("%d",inversioncount(arr,0,n-1));



}
