#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p=par(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
    }
}
int par(int arr[],int l,int h)
{
    int p=arr[h];//last elmet as piovt
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<p)//quick osrt condidiotn check arr[i]<p
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);
    return i+1;


}
int main()
{
    int n;
  scanf("%d",&n);
  int arr[n];

  for(int i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  quicksort(arr,0,n-1);
  //array,left index,right index
  for(int i=0;i<n;i++)
  {
      printf("%d ",arr[i]);
  }
}
