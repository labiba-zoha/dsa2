#include<bits/stdc++.h>
using namespace std;
struct Job{
    char id;
    int deadline;
    int profit;
};
Job jobs[1000];
int n;
bool compartor(Job a,Job b)
{
    return a.profit>b.profit;
}
void jobseq()
{
    sort(jobs,jobs+n,compartor);
    //first sort by descding order by profit

    //we need to build the slot for it we nned the maxium dealing when all job will be finshwd
    int maxdead=0;
    for(int i=0;i<n;i++)
    {
        maxdead=max(maxdead,jobs[i].deadline);
    }
        vector<bool>slot(maxdead+1,false);//now build the slot;
        vector<char>jobprint(maxdead+1,'\0');
        int profit=0;
        //assginent job to slot
        for(int i=0;i<n;i++)
        {
            for(int j=min(maxdead,jobs[i].deadline);j>0;j--) //as we can do the job current tiem or early not after thar line
            {
                if(slot[j]==false)//empty//j>0 as 0 dealine ot possible
                {
                    jobprint[j]=jobs[i].id;
                    profit+=jobs[i].profit;
                    slot[j]=true;
                    //fill
                    break;

                }
            }

        }
        for(int i=1;i<=maxdead;i++)
        {
            if(jobprint[i]!='\0')//there may be cases where soem slot arenot fill
            {
                printf("%c ",jobprint[i]);
            }
        }
        printf("\n");
        printf("the maxium profit %d ",profit);
    }


int main()
{
   cout<<"enter the number of jobs";
   cin>>n;
   cout<<"enter the job destails(Id,deadline,profilt)";
   for(int i=0;i<n;i++)
   {
       cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
   }
   jobseq();

}
