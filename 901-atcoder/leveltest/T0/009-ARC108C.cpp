#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 100001

using namespace std;
vector<pair<int,int>> graph[LEN];
vector<pair<int,int>> tree[LEN];
bool check[LEN]={0};
int color[LEN]={0};

void dfs(int cur, int p)
{
    check[cur]=1;
    for(auto&p : graph[cur])
    {
        int next=p.first;
        if(check[next]) continue;
        tree[cur].push_back(p);
        dfs(next,cur);
    }
}

void dfs2(int cur, int p, int bef, int n)
{

    for(auto&p : tree[cur])
    {
        int next=p.first;
        int c=p.second;
        if(color[cur]==0 && bef!=c) color[cur]=c;
        if(color[cur]!=c) color[next]=c;
        dfs2(next,cur,color[cur],n);
    }
    if(color[cur]==0)
    {
        if(color[p]==n) color[cur]=1;
        else color[cur]=n;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        if(check[i]==0)
        {
            cout<<"No";
            return 0;
        }
    }
    dfs2(1,0,0,n);
    for(int i=1;i<=n;i++) cout<<color[i]<<"\n";
}