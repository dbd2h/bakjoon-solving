#include <iostream>
#include <vector>
#include <queue>

#define LEN 501

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
    dist[cur]=INF;
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> xV[LEN];
    vector<int> yV[LEN];
    bool xArr[LEN]={0};
    bool yArr[LEN]={0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        xV[a].push_back(b);
        yV[b].push_back(a);
        xArr[a]=1;
        yArr[b]=1;
    }

    for(int i=1;i<=500;i++)
    {
        if(xV[i].size()==0) continue;
        for(auto y : xV[i])
        {
            graph[i].push_back(y);
        }
    }
    int res=0;
    while(bfs(500))
    {
        for(int i=1;i<=500;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    int xCount=0;
    int yCount=0;
    for(int i=1;i<=500;i++)
    {
        xCount+=xArr[i];
        yCount+=yArr[i];
    }
    if(res!=xCount || res!=yCount) cout<<"Mirko";
    else cout<<"Slavko";
}