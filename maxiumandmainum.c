#include<stdio.h>
struct Minmax{
    int min;
    int max;
};
typedef struct Minmax Minmax;//same name
Minmax find(int arr[],int low,int high)
{
    if(low==high)
    {
        return (Minmax){arr[low],arr[low]};
    }
    else if(low+1==high)
    {
        if(arr[low]<arr[high])
        {
            return (Minmax){arr[low],arr[high]};
        }
        else
        {
             return (Minmax){arr[high],arr[low]};
        }
    }
    else
    {
        int mid=(low+high)/2;
        Minmax l=find(arr,low,mid);
        Minmax r=find(arr,mid+1,high);
        Minmax result;
        result.min=(l.min<r.min)?l.min:r.min;
        result.max=(l.max>r.max)?l.max:r.max;
        return result;
    }
}
int main(){
     int n;


    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    Minmax result = find(arr, 0, n - 1);


    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);

    return 0;
}
