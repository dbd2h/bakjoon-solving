#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define INF 1e18

typedef long long ll;

using namespace std;

vector<ll> graph[2501];
ll lmatch[2501];
map<ll, int> rmatch;
ll dist[2501];

bool bfs(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(lmatch[i]==INF)
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
    int n;
    cin>>n;
    ll numArr[2501][2];
    for(int i=1;i<=n;i++)
    {
        cin>>numArr[i][0]>>numArr[i][1];
        graph[i].push_back((ll)numArr[i][0]+(ll)numArr[i][1]);
        graph[i].push_back((ll)numArr[i][0]-(ll)numArr[i][1]);
        graph[i].push_back((ll)numArr[i][0]*(ll)numArr[i][1]);
    }
    int res=0;
    for(int i=1;i<=n;i++) lmatch[i]=INF;
    while(bfs(n))
    {
        for(int i=1;i<=n;i++)
        {
            if(lmatch[i]==INF && dfs(i)) res++;
        }
    }
    if(res!=n)
    {
        cout<<"impossible";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ll a=numArr[i][0];
        ll b=numArr[i][1];
        if(a+b==lmatch[i])
        {
            cout<<a<<" + "<<b<<" = "<<lmatch[i]<<"\n";
        }
        else if(a-b==lmatch[i])
        {
            cout<<a<<" - "<<b<<" = "<<lmatch[i]<<"\n";
        }
        else if(a*b==lmatch[i])
        {
            cout<<a<<" * "<<b<<" = "<<lmatch[i]<<"\n";
        }
    }
}