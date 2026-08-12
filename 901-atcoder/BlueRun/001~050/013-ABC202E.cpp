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
#define LEN 200001

using namespace std;
int t=0;
vector<int> graph[LEN];
int tin[LEN];
int tout[LEN];
int level[LEN];
vector<int> levelV[LEN];

void dfs(int cur, int p, int l)
{
    t++;
    tin[cur]=t;
    level[cur]=l;
    levelV[l].push_back(t);
    for(auto&next : graph[cur])
    {
        if(next==p) continue;
        dfs(next,cur,l+1);
    }
    tout[cur]=t;
}

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    dfs(1,0,1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        b++;
        int res=0;
        if(level[a]<=b)
        {
            res=upper_bound(levelV[b].begin(),levelV[b].end(),tout[a])-lower_bound(levelV[b].begin(),levelV[b].end(),tin[a]);
        }
        cout<<res<<"\n";
    }
}