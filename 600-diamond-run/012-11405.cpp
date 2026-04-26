#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int graph[203][203]={0};
int cost[203][203]={0};

int mcmf(int len)
{
    int dist[203];
    int parent[203];
    bool inQ[203]={0};
    for(int i=1;i<=len;i++)
    {
        dist[i]=INF;
        parent[i]=-1;
    }
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        inQ[cur]=0;
        for(int i=2;i<=len;i++)
        {
            if(graph[cur][i]==0) continue;
            int w=dist[cur]+cost[cur][i];
            if(dist[i]<=w) continue;
            dist[i]=w;
            parent[i]=cur;
            if(inQ[i]) continue;
            q.push(i);
            inQ[i]=1;
        }
    }
    if(dist[2]==INF) return -1;
    vector<int> flowV;
    int idx=2;
    while(idx!=-1)
    {
        flowV.push_back(idx);
        idx=parent[idx];
    }
    int vLen=flowV.size();
    int res=0;
    for(int i=vLen-1;i>0;i--)
    {
        int a=flowV[i];
        int b=flowV[i-1];
        graph[a][b]--;
        res+=cost[a][b];
        if(a!=1 && b!=2)
        {
            graph[b][a]++;
            cost[b][a]=-cost[a][b];
        }
    }
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=3;i<=n+2;i++)
    {
        cin>>graph[i][2];
    }
    for(int i=n+3;i<=n+m+2;i++)
    {
        cin>>graph[1][i];
    }
    for(int i=n+3;i<=n+m+2;i++)
    {
        for(int j=3;j<=n+2;j++)
        {
            int c;
            cin>>c;
            graph[i][j]=100;
            cost[i][j]=c;
        }
    }
    int res=0;
    while(true)
    {
        int flow=mcmf(n+m+2);
        if(flow==-1) break;
        res+=flow;
    }
    cout<<res;
}