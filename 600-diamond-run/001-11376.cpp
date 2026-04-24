#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[2001];
int dist[2001];
int lmatch[2001]={0};
int rmatch[1001]={0};

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
        for(auto &w : graph[cur])
        {
            int emp=rmatch[w];
            if(emp==0) found=true;
            else if(dist[emp]==INF)
            {
                q.push(emp);
                dist[emp]=dist[cur]+1;
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto& w : graph[cur])
    {
        int emp=rmatch[w];
        if(emp==0 || dist[emp]==dist[cur]+1 && dfs(emp))
        { 
            lmatch[cur]=w;
            rmatch[w]=cur;
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
        int len;
        cin>>len;
        for(int j=0;j<len;j++)
        {
            int num;
            cin>>num;
            graph[i*2-1].push_back(num);
            graph[i*2].push_back(num);
        }
    }
    while(bfs(n*2))
    {
        for(int i=1;i<=n*2;i++)
        {
            if(lmatch[i]==0) dfs(i);
        }
    }
    int res=0;
    for(int i=1;i<=m;i++)
    {
        if(rmatch[i]==0) continue;
        res++;
    }
    cout<<res;
}