#include <iostream>
#include <vector>
using namespace std;
int minJumps(vector<int>&arr)
{
    int n=arr.size();
    if(arr[0]==0)
        return -1;
    int maxreach=0;
    int currreach=0;
    int jump=0;
    for(int i=0;i<n;i++)
    {
        maxreach=max(maxreach,i+arr[i]);
        if(maxreach>=n-1)
            return jump+1;
        if(i==currreach)
        {
            if(i==maxreach)
            {
                return-1;
            }
            else
            {
                jump++;
                currreach=maxreach;
            }
        }
    }
    return -1;



}
int main() {
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << minJumps(arr);
    return 0;
}

