#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[1001];
int dist[1001];
int lmatch[1001]={0};
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
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int len;
        cin>>len;
        for(int j=0;j<len;j++)
        {
            int num;
            cin>>num;
            graph[i].push_back(num);
        }
    }
    while(bfs(n))
    {
        for(int i=1;i<=n;i++)
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
    int count=0;
    bool isF=false;
    for(int i=1;i<=n;i++)
    {
        for(auto&next : graph[i])
        {
            if(rmatch[next]!=0) continue;
            count++;
            rmatch[next]=i;
            if(count==k || res+count==m)
            {
                isF=true;
                break;
            }
        }
        if(isF) break;
    }
    cout<<res+count;
}