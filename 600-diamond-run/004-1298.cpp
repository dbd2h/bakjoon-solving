#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[101];
int lmatch[101]={0};
int rmatch[101]={0};
int dist[101];

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
        for(auto &nb : graph[cur])
        {
            int st=rmatch[nb];
            if(st==0) found=true;
            else if(dist[st]==INF)
            {
                dist[st]=dist[cur]+1;
                q.push(st);
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto &nb : graph[cur])
    {
        int st=rmatch[nb];
        if(st==0 || (dist[st]==dist[cur]+1 && dfs(st))) 
        {
            lmatch[cur]=nb;
            rmatch[nb]=cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    while(bfs(n))
    {
        for(int i=1;i<=n;i++)
        {
            if(lmatch[i]==0) dfs(i);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(rmatch[i]==0) continue;
        res++;
    }
    cout<<res;
}