#include<bits/stdc++.h>
using namespace std;
bool mycompare(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second<p2.second)
        return true;
    return false;
}
  void printMAXactivies(vector<pair<int,int>>&arr)
 {
     int i=0;
     sort(arr.begin(),arr.end(),mycompare);
     //for(int k=0;k<arr.size();k++)
     //{
        // cout<<arr[k].first<<" "<<arr[k].second<<endl;
     //}
     cout<<i<<endl;
     for(int j=1;j<arr.size();j++)
     {
         if(arr[j].first>=arr[i].second)
         {
             cout<<j<<endl;
             i=j;
         }
     }
 }
int main()
{
    vector<pair<int,int>>arr;
    arr.push_back(make_pair(5,9));
     arr.push_back(make_pair(5,7));
     arr.push_back(make_pair(8,9));
     arr.push_back(make_pair(0,6));
     arr.push_back(make_pair(3,4));
     arr.push_back(make_pair(1,2));
     printMAXactivies(arr);

}
