#include <iostream>
#include <vector>
#include <queue>

#define LEN 513

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
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> bV;
    vector<pair<int,int>> kV;
    for(int i=0;i<k;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c==0) bV.push_back({a,b});
        else if(c==1) kV.push_back({a,b});
    }
    int bLen=bV.size();
    for(int i=0;i<bLen;i++)
    {
        for(int j=0;j<kV.size();j++)
        {
            if(bV[i].first==kV[j].first || bV[i].second==kV[j].second) graph[i+1].push_back(j+1);
        }
    }
    int res=0;
    while(bfs(bLen))
    {
        for(int i=1;i<=bLen;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    cout<<res;
}
