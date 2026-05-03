#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[1001];
int lmatch[1001]={0};
int rmatch[1001]={0};
int dist[1001];
bool lV[1001]={0};
bool rV[1001]={0};

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
        for(auto&rNode : graph[cur])
        {
            int lNode=rmatch[rNode];
            if(lNode==0) found=true;
            else if(dist[lNode]==INF)
            {
                dist[lNode]=dist[cur]+1;
                q.push(lNode);
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto &rNode : graph[cur])
    {
        int lNode=rmatch[rNode];
        if(lNode==0 || (dist[lNode]==dist[cur]+1 && dfs(lNode)))
        {
            lmatch[cur]=rNode;
            rmatch[rNode]=cur;
            return true;
        }
    }
    return false;
}

void resMaker(int cur, bool isL)
{
    if(isL)
    {
        if(lV[cur]) return;
        lV[cur]=1;
        for(auto& r : graph[cur])
        {
            if(lmatch[cur]==r) continue;
            resMaker(r,!isL);
        }
    }
    else
    {
        if(rV[cur]) return;
        rV[cur]=1;
        resMaker(rmatch[cur],!isL);
    }
    return;
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
            int r;
            cin>>r;
            graph[i].push_back(r);
        }
    }
    int res=0;
    while(bfs(n))
    {
        for(int i=1;i<=n;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    cout<<res<<"\n";
    
    for(int i=1;i<=n;i++)
    {
        if(lmatch[i]==0) resMaker(i,1);
    }
    int resL=0;
    for(int i=1;i<=n;i++)
    {
        if(!lV[i]) resL++;
    }
    cout<<resL<<" ";
    for(int i=1;i<=n;i++)
    {
        if(!lV[i]) cout<<i<<" ";
    }
    cout<<"\n";
    int resR=0;
    for(int i=1;i<=m;i++)
    {
        if(rV[i]) resR++;
    }
    cout<<resR<<" ";
    for(int i=1;i<=m;i++)
    {
        if(rV[i]) cout<<i<<" ";
    }
}