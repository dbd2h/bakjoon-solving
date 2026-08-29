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
bool color[LEN];

void dfs(int cur, int parent)
{
    for(auto&p : graph[cur])
    {
        int next=p.first;
        int w=p.second;
        if(next==parent) continue;
        if(w%2==1) color[next]=!color[cur];
        else color[next]=color[cur];
        dfs(next,cur);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    color[1]=0;
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<"\n";
    }
}