#include<bits/stdc++.h>
using namespace std;
struct Job{
    char id;
    int deadline;
    int profit;
};
Job jobs[1000];
int n;

int main()
{
   cout<<"enter the number of jobs";
   cin>>n;
   cout<<"enter the job destails(Id,deadline,profilt)";
   for(int i=0;i<n;i++)
   {
       cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
   }
}
