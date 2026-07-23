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

vector<int> graph[LEN];
ll cArr[LEN];
ll dist[LEN]={0};

void dfs(int cur, int p)
{
    for(auto&next : graph[cur])
    {
        if(next==p) continue;
        dfs(next,cur);
        dist[cur]+=(dist[next]+cArr[next]);
        cArr[cur]+=cArr[next];
    }
}   

void resMaker(int cur, int p)
{
    if(p!=0) 
    {
        dist[cur]=dist[p]+(cArr[1]-cArr[cur]*2);
    }
    for(auto&next : graph[cur])
    {
        if(next==p) continue;
        resMaker(next,cur);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++) cin>>cArr[i];
    dfs(1,0);
    resMaker(1,0);
    ll res=dist[1];
    for(int i=2;i<=n;i++) res=min(res,dist[i]);
    cout<<res;
}