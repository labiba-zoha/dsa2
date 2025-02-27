#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u;
    int v;
    int w;
};
void bellman(vector<edge>&graph,int v,int source)
{
    vector<int>dis(v,INT_MAX);
    dis[source]=0;
    for(int i=0;i<v-1;i++)
    {
        for(size_t j=0;j<graph.size();j++)
        {
            const edge &e=graph[j];
            if(dis[e.u]!=INT_MAX&&dis[e.u]+e.w<dis[e.v])
            {
                dis[e.v]=dis[e.u]+e.w;
            }
        }
    }
    for(size_t j=0;j<graph.size();j++)
        {
            const edge &e=graph[j];
            if(dis[e.u]!=INT_MAX&&dis[e.u]+e.w<dis[e.v])
            {
                printf("naegaative cycle exits\n");
            }
        }
        for(int i=0;i<v;i++)
        {
            cout<<i<<"-"<<dis[i]<<endl;
        }

}
int main()
{   int v=6;
    vector<edge>graph={{0,1,5},{0, 2, 7},
        {1, 2, 3},
        {1, 3, 4},
        {1, 4, 6},
        {3, 4, -1},
        {3, 5, 2},
        {4, 5, -3}};
        bellman(graph,v,0);

}
