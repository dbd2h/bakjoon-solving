#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[10001];
int lmatch[10001]={0};
int rmatch[10001]={0};
int dist[10001];

bool bfs(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(lmatch[i]==0)
        {
            q.push(i);
            dist[i]=0;
        }
        else dist[i]=INF;
    }
    bool found=false;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto& col : graph[cur])
        {
            int row=rmatch[col];
            if(row==0) found=true;
            else if(dist[row]==INF)
            {
                q.push(row);
                dist[row]=dist[cur]+1;
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto& col : graph[cur])
    {
        int row=rmatch[col];
        if(row==0 || (dist[row]==dist[cur]+1 && dfs(row)))
        {
            lmatch[cur]=col;
            rmatch[col]=cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    bool arr[101][101]={0};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
    }
    int idx=1;
    int upDia[101][101]={0};
    int downDia[101][101]={0};
    
    for(int i=1;i<n*2;i++)
    {
        bool isInput=false;
        for(int j=min(n,i);j>=1 && i-j+1<=n;j--)
        {
            int x=i-j+1;
            int y=j;
            if(arr[x][y])
            {
                if(isInput) idx++;
                isInput=false;
            }
            else
            {
                upDia[x][y]=idx;
                isInput=true;
            }
        }
        if(isInput) idx++;
    }
    idx=1;
    for(int i=n-1;i>=-n+1;i--)
    {
        bool isInput=false;
        for(int j=1;j<=n;j++)
        {
            int x=i+j;
            int y=j;
            if(!(x>=1 &&x<=n && y>=1 && y<=n)) continue;
            if(arr[x][y])
            {
                if(isInput) idx++;
                isInput=false;
            }
            else
            {
                downDia[x][y]=idx;
                isInput=true;
            }
        }
        if(isInput) idx++;
    }
    int len=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i][j]) continue;
            if(upDia[i][j]>len) len=upDia[i][j];
            graph[upDia[i][j]].push_back(downDia[i][j]);
        }
    }
    int res=0;
    while(bfs(len))
    {
        for(int i=1;i<=len;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    cout<<res;
}
