#include <iostream>
#include <vector>
#include <queue>

#define LEN 2001

#define INF 1e9

using namespace std;

vector<int> graph[LEN];
int lmatch[LEN]={0};
int rmatch[LEN]={0};
int dist[LEN];

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
        for(auto& r : graph[cur])
        {
            int l=rmatch[r];
            if(l==0) found=true;
            else if(dist[l]==INF)
            {
                q.push(l);
                dist[l]=dist[cur]+1;
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto& r : graph[cur])
    {
        int l=rmatch[r];
        if(l==0 || (dist[l]==dist[cur]+1 && dfs(l)))
        {
            lmatch[cur]=r;
            rmatch[r]=cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    bool isC[LEN]={0};
    for(int i=1;i<=n;i++)
    {
        int num;
        char a;
        cin>>num>>a;
        if(a=='c')
        {
            isC[i]=1;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(isC[a])
        {
            graph[a].push_back(b);
        }
        else if(isC[b])
        {
            graph[b].push_back(a);
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
    cout<<n-res;
}