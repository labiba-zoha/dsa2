#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     vector <int>a={4,3,2};
     //minum cost is (size-1)*minof all elemnts
     int n=a.size();
     int cost=(n-1)*(*min_element(a.begin(),a.end()));
     cout<<cost<<endl;
 }




