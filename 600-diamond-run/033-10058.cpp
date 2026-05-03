#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

typedef long long ll;

using namespace std;

vector<int> graph[101];
int lmatch[101]={0};
int rmatch[101]={0};
int dist[101];
bool leftN[101]={0};
bool rightN[101]={0};

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

void resMaker(int cur, bool isL)
{
    if(isL)
    {
        if(leftN[cur]) return;
        leftN[cur]=1;
        for(auto& next : graph[cur])
        {
            if(lmatch[cur]==next) continue;
            resMaker(next,!isL);
        }
    }
    else
    {
        if(rightN[cur]) return;
        rightN[cur]=1;
        resMaker(rmatch[cur],!isL);
    }
    return;
}

int main()
{
    ll n,d;
    cin>>n>>d;
    ll arr[101][101];
    ll coor[101][2];
    for(int i=1;i<=n;i++)
    {
        cin>>coor[i][0]>>coor[i][1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ll x=coor[i][0]-coor[j][0];
            ll y=coor[i][1]-coor[j][1];
            arr[i][j]=x*x+y*y;
        }
    }
    ll c=d*d;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(c<arr[i][j]) graph[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(lmatch[i]==0) resMaker(i,1);
    }
    vector<int> resV;
    for(int i=1;i<=n;i++) if(leftN[i]==1) resV.push_back(i);
    int res=0;
    for(auto& i : resV)
    {
        if(rightN[i]) continue;
        res++;
    }
    cout<<res<<"\n";
    for(auto& i : resV)
    {
        if(rightN[i]) continue;
        cout<<i<<" ";
    }
}