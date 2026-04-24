#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
int empArr[1001]={0};
int wArr[1001]={0};
int dist[1001];

bool bfs(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(empArr[i]==0)
        {
            dist[i]=0;
            q.push(i);
        }
        else dist[i]=-1;
    }
    bool found=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto& next : graph[cur])
        {
            int emp=wArr[next];
            if(emp==0) found=1;
            else if(dist[emp]==-1)
            {
                dist[emp]=dist[cur]+1;
                q.push(emp);
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto &next : graph[cur])
    {
        int emp=wArr[next];
        if(emp==0 || (dist[emp]==dist[cur]+1 && dfs(emp)))
        {
            empArr[cur]=next;
            wArr[next]=cur;
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
        int num;
        cin>>num;
        for(int j=0;j<num;j++)
        {
            int w;
            cin>>w;
            graph[i].push_back(w);
        }
    }
    while(bfs(n))
    {
        for(int i=1;i<=n;i++)
        {
            if(empArr[i]!=0) continue;
            dfs(i);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(empArr[i]==0) continue;
        res++;
    }
    cout<<res;
}