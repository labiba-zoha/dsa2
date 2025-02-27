#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(int arr[],int l,int h,int type)
{
    if(l<h)
    {
        int p=par(arr,l,h,type);
        quicksort(arr,l,p-1,type);
        quicksort(arr,p+1,h,type);
    }
}
int par(int arr[],int l,int h,int type)
{
    int p;
    if(type==1)//first elemt as pivost
    {
      swap(&arr[l],&arr[h]);
      p=arr[h];
    }
    else if(type==2)
    {
        p=arr[h];
    }
    else
    {
        int mid=(l+h)/2;
        swap(&arr[mid],&arr[h]);
        p=arr[h];
    }


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


 while(1)
 {
     int choice;
     printf(" 1:first elemt as /n2.lastelemt/n3.middleelmet");
     scanf("%d",&choice);

     if(choice==1)
     {

          quicksort(arr,0,n-1,1);

          for(int i=0;i<n;i++)
          {
              printf("%d ",arr[i]);
          }
          printf("\n");

     }
    else if(choice==2)
     {

          quicksort(arr,0,n-1,2);

          for(int i=0;i<n;i++)
          {
              printf("%d ",arr[i]);
          }
          printf("\n");

     }
    else if(choice==3)
     {


          quicksort(arr,0,n-1,3);

          for(int i=0;i<n;i++)
          {
              printf("%d ",arr[i]);
          }
          printf("\n");

     }
     else{
        break;
     }
 }
}

