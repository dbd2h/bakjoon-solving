#include <iostream>
#include <queue>

#define INF 1e9

using namespace std;

bool graph[201][201];
int lmatch[201]={0};
int rmatch[201]={0};
int dist[201];

bool bfs(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(lmatch[i]==0)
        {
            dist[i]=0;
            q.push(i);
        }
        else dist[i]=INF;
    }
    bool found=false;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(graph[cur][i]==0) continue;
            int l=rmatch[i];
            if(l==0) found=true;
            else if(dist[l]==INF)
            {
                dist[l]=dist[cur]+1;
                q.push(l);
            }
        }
    }
    return found;
}

bool dfs(int cur, int n)
{
    for(int i=1;i<=n;i++)
    {
        if(graph[cur][i]==0) continue;
        int l=rmatch[i];
        if(l==0 || (dist[l]==dist[cur]+1 && dfs(l,n)))
        {
            lmatch[cur]=i;
            rmatch[i]=cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) graph[i][j]=1;
    }
    for(int i=0;i<m;i++)
    {
        int num,x,y,v;
        cin>>num>>x>>y>>v;
        if(num==1)
        {
            for(int j=x;j<=y;j++)
            {
                for(int k=v+1;k<=n;k++)
                {
                    graph[j][k]=0;
                }
            }
            for(int j=x-1;j>=1;j--)
            {
                graph[j][v]=0;
            }
            for(int j=y+1;j<=n;j++)
            {
                graph[j][v]=0;
            }
        }
        else if(num==2)
        {
            for(int j=x;j<=y;j++)
            {
                for(int k=v-1;k>=1;k--)
                {
                    graph[j][k]=0;
                }
            }
            for(int j=x-1;j>=1;j--)
            {
                graph[j][v]=0;
            }
            for(int j=y+1;j<=n;j++)
            {
                graph[j][v]=0;
            }
        }
    }
    int tot=0;
    while(bfs(n))
    {
        for(int i=1;i<=n;i++)
        {
            if(lmatch[i]==0 && dfs(i,n)) tot++;
        }
    }
    if(tot<n)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++) cout<<lmatch[i]<<" ";
}