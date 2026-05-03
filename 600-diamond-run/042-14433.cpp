#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define LEN 301

#define INF 1e9

using namespace std;

int lmatch[LEN];
int rmatch[LEN];
int dist[LEN];

bool bfs(vector<int> graph[LEN], int n)
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

bool dfs(vector<int> graph[LEN], int cur)
{
    for(auto& r : graph[cur])
    {
        int l=rmatch[r];
        if(l==0 || (dist[l]==dist[cur]+1 && dfs(graph,l)))
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
    int n,m,k1,k2;
    cin>>n>>m>>k1>>k2;
    vector<int> graph1[LEN];
    vector<int> graph2[LEN];
    for(int i=0;i<k1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph1[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        lmatch[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        rmatch[i]=0;
    }
    int res1=0;
    while(bfs(graph1,n))
    {
        for(int i=1;i<=n;i++)
        {
            if(lmatch[i]==0 && dfs(graph1,i)) res1++;
        }
    }
    for(int i=0;i<k2;i++)
    {
        int a,b;
        cin>>a>>b;
        graph2[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        lmatch[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        rmatch[i]=0;
    }
    int res2=0;
    while(bfs(graph2,n))
    {
        for(int i=1;i<=n;i++)
        {
            if(lmatch[i]==0 && dfs(graph2,i)) res2++;
        }
    }
    if(res1>=res2) cout<<"그만 알아보자";
    else cout<<"네 다음 힐딱이";
}