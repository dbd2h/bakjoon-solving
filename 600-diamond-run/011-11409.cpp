#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

bool graph[802][802]={0};
int cost[802][802]={0};

int mcmf(int n, int m)
{
    queue<int> q;
    bool inQ[802]={0};
    int parent[802];
    int dist[802];
    for(int i=0;i<n+m+2;i++)
    {
        dist[i]=INF;
        parent[i]=-1;
    } 
    dist[0]=0;
    q.push(0);
    inQ[0]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        inQ[cur]=0;
        for(int i=1;i<n+m+2;i++)
        {
            if(graph[cur][i]==0) continue;
            int w=dist[cur]+cost[cur][i];
            if(dist[i]!=INF && dist[i]>=w) continue;
            dist[i]=w;
            parent[i]=cur;
            if(inQ[i]==0)
            {
                q.push(i);
                inQ[i]=1; 
            }
        }
    }
    if(dist[1]==INF) return -1;
    vector<int> flowV;
    int idx=1;
    while(idx!=-1)
    {
        flowV.push_back(idx);
        idx=parent[idx];
    }
    int len=flowV.size();
    int res=0;
    for(int i=len-1;i>0;i--)
    {
        int a=flowV[i];
        int b=flowV[i-1];
        res+=cost[a][b];
        graph[a][b]=0;
        if(a!=0 && b!=1)
        {
            graph[b][a]=1;
            cost[b][a]=-cost[a][b];
        }
    }
    return res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=2;i<n+2;i++)
    {
        graph[0][i]=1;
    }
    for(int i=n+2;i<n+m+2;i++)
    {
        graph[i][1]=1;
    }
    for(int i=2;i<n+2;i++)
    {
        int len;
        cin>>len;
        for(int j=0;j<len;j++)
        {
            int w,c;
            cin>>w>>c;
            graph[i][n+1+w]=1;
            cost[i][n+1+w]=c;
        }
    }
    int res=0;
    int count=0;
    while(true)
    {
        int flow=mcmf(n,m);
        if(flow==-1) break;
        res+=flow;
        count++;
    }
    cout<<count<<"\n";
    cout<<res;
}