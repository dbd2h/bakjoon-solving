#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int lmatch[1001];
int rmatch[1001];
int dist[1001];

bool bfs(vector<int> graph[1001], int n)
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(lmatch[i]==-1)
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
        for(auto&rNode : graph[cur])
        {
            int lNode=rmatch[rNode];
            if(lNode==-1) found=true;
            else if(dist[lNode]==INF)
            {
                dist[lNode]=dist[cur]+1;
                q.push(lNode);
            }
        }
    }
    return found;
}

bool dfs(vector<int> graph[1001], int cur)
{
    for(auto &rNode : graph[cur])
    {
        int lNode=rmatch[rNode];
        if(lNode==-1 || (dist[lNode]==dist[cur]+1 && dfs(graph,lNode)))
        {
            lmatch[cur]=rNode;
            rmatch[rNode]=cur;
            return true;
        }
    }
    return false;
}

void problem()
{
    int n,m;
    cin>>n>>m;
    vector<int> graph[1001];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        lmatch[i]=-1;
        rmatch[i]=-1;
    }
    while(bfs(graph,n))
    {
        for(int i=0;i<n;i++)
        {
            if(lmatch[i]==-1 && dfs(graph,i)) res++;
        }
    }
    cout<<res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}