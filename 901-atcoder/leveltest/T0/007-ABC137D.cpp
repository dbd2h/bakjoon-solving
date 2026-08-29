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
#define LEN 100005

using namespace std;

priority_queue<pair<int,int>> pq;
int parent[LEN];

int findP(int a)
{
    if(a==parent[a]) return a;
    parent[a]=findP(parent[a]);
    return parent[a];
}

int main()
{
    int n,m;
    cin>>n>>m;
    ll res=0;
    for(int i=1;i<=m+1;i++) parent[i]=i;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        pq.push({b,a});
    }
    while(!pq.empty())
    {
        int a=pq.top().first;
        int b=pq.top().second;
        pq.pop();
        if(b>m) continue;
        int p=findP(b);
        if(p==m+1) continue;
        if(p==m) parent[p]=m+1;
        else parent[p]=findP(p+1);
        res+=a;
    }
    cout<<res;
}