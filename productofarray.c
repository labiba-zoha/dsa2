#include<stdio.h>
int productofarrays(int arr[],int n,int i)
{
    if(i==n)
        return 1;//arrayfinsh
    else{
        return (arr[i]*productofarrays(arr,n,i+1));
    }
}
int sumofarrays(int arr[],int n,int i)
{
    if(i==n)
        return 0;
    else
        return (arr[i]+sumofarrays(arr,n,i+1));
}
int main()
{
    int n;
    int arr[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d\n",productofarrays(arr,n,0));//as i=0 start;
    printf("%d",sumofarrays(arr,n,0));

}
