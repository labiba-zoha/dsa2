#include<stdio.h>

void merge(int arr1[],int arr2[],int arr[],int n1,int n2,int n3)
{

    int i=0,j=0,k=0;



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
    int arr1[6]={1,5,7,8,10,12};
    int arr2[6]={4,6,7,9,13,14};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int n3=n1+n2;
    int arr[n3];
    merge(arr1,arr2,arr,n1,n2,n3);
   for(int i=0;i<n3;i++)
   {
       printf("%d ",arr[i]);
   }
}

