
#include<stdio.h>
void mergesort(int arr[],int l,int r)
{
    if(l<r)//l<r means one elmet
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void merge(int arr[],int l,int mid,int r)
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
    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(arr1[i]<=arr2[j])//ascding deceding >=
        {
            arr[k]=arr1[i];
            i++;

        }
        else
        {
            arr[k]=arr2[j];
            j++;
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
  mergesort(arr,0,n-1);
 int k;

 scanf("%d",&k);
 if(k>0&&k<=n)
 {
     printf("%d",arr[k-1]);
 }



}
