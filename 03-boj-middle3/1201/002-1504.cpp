#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minDistance(vector<pair<int,int>> (&graph)[801], int s, int f, int n)
{
    bool check[801]={0};
    int weight[801]={0};
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        int cur=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        if(check[cur]) continue;
        if(f==cur) return w;
        check[cur]=1;
        weight[cur]=w;
        for(int i=0;i<graph[cur].size();i++)
        {
            int next=graph[cur][i].first;
            int w1=graph[cur][i].second;
            if(check[next]) continue;
            if(weight[next]!=0 && w+w1>=weight[next]) continue;
            weight[next]=w+w1;
            pq.push({weight[next],next});
        }
    }
    return -1;
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> graph[801];
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int v1,v2;
    cin>>v1>>v2;
    int sToV1=minDistance(graph,1,v1,n);
    int sToV2=minDistance(graph,1,v2,n);
    int v1ToV2=minDistance(graph,v1,v2,n);
    int fToV1=minDistance(graph,n,v1,n);
    int fToV2=minDistance(graph,n,v2,n);
    int res=-1;
    if(sToV1!=-1 && v1ToV2!=-1 && fToV2!=-1)
    {
        if(res==-1 || res>sToV1+v1ToV2+fToV2) res=sToV1+v1ToV2+fToV2;
    }
    if(sToV2!=-1 && v1ToV2!=-1 && fToV1!=-1)
    {
        if(res==-1 || res>sToV2+v1ToV2+fToV1) res=sToV2+v1ToV2+fToV1;
    }
    cout<<res;
}