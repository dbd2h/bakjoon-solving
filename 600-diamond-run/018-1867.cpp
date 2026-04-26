#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[501];
int lmatch[501]={0};
int rmatch[501]={0};
int dist[501];

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
        for(auto&col : graph[cur])
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
    for(auto &col : graph[cur])
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
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    int res=0;
    while(bfs(n))
    {
        for(int i=1;i<=n;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    cout<<res;
}