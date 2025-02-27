#include<stdio.h>
void printarray(int arr[],int n,int i)
{
    if(i==n)
    return;

    printf("%d",arr[i]);
    printarray(arr,n,i+1);

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
    printarray(arr,n,0);
}
