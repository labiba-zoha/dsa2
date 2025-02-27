#include<bits/stdc++.h>
using namespace std;
struct sort_pred
{
     bool operator () (const std::pair<int,int> &left, const std::pair<int,int> &right)
     {
          int r1=left.first/left.second;
          int r2= right.first/right.second;
          if(r1>r2)
          {
               return true;
          }
          return false;

     }
};
void printMaxProfit(vector <pair<int,int>> &arr, int w)
{
     int i=0;
     int profit=0;
     sort(arr.begin(), arr.end(), sort_pred());
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
