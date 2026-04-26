#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[301];
int lmatch[301]={0};
int rmatch[301]={0};
int dist[301];

bool bfs(int r)
{
    queue<int> q;
    for(int i=1;i<=r;i++)
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
                dist[row]=dist[cur]+1;
                q.push(row);
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
    int r,c,n;
    cin>>r>>c>>n;
    int arr[301][301]={0};
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(arr[i][j]) continue;
            graph[i].push_back(j);
        }
    }
    int res=0;
    while(bfs(r))
    {
        for(int i=1;i<=r;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    cout<<res;
}