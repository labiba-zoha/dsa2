#include<bits/stdc++.h>
using namespace std;
bool mycompare(pair<int ,int>p1,pair<int,int>p2)
{
    int r1=p1.first/p1.second;
          int r2= p2.first/p2.second;
          if(r1>r2)
          {
               return true;
          }
          return false;
}
void printMaxProfit(vector <pair<int,int>> &arr, int w)
{
     int i=0;
     int profit=0;
     sort(arr.begin(), arr.end(), mycompare);
     for(int k=0;k<arr.size();k++)
     {
           cout<<arr[k].first<<" "<<arr[k].second<<endl;
          if(w<=arr[k].second)
          {
             double r=(double)w/(double)arr[k].second;
             profit+=arr[k].first*r;
             //w-=w/arr[k].first;
          }
          else
          {
            w=w-arr[k].second;
            profit+=arr[k].first;
          }
     }
     cout<<profit<<endl;


}


int main()
{
     vector < pair<int,int> > arr;
     arr.push_back(make_pair(60,10));//first profit second weigh
     arr.push_back(make_pair(100,20));
     arr.push_back(make_pair(120,30));
     int w=50;
     printMaxProfit(arr,w);

     //cout<<arr[1].first<<" "<<arr[1].second<<endl;

}

