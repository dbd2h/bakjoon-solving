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

vector<int> graph[LEN];
set<int> s;
int parent[LEN];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++) parent[i]=-1;
    parent[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto&next : graph[cur])
        {
            if(parent[next]==next || (parent[next]!=-1 && parent[next]<=parent[cur])) continue;
            if(next>parent[cur]) parent[next]=next;
            else parent[next]=parent[cur];
            q.push(next);
        }
    }
    int atMost=1;
    for(int i=1;i<=n;i++)
    {
        if(atMost!=-1) atMost=max(atMost,parent[i]);
        if(parent[i]==-1) atMost=-1;
        for(auto&next : graph[i])
        {
            if(next<i) continue;
            s.insert(next);
        }
        while(!s.empty() && *s.begin()<=i) s.erase(*s.begin());
        int res=s.size();
        if(i<atMost || atMost==-1) res=-1;
        cout<<res<<"\n";
    }
}