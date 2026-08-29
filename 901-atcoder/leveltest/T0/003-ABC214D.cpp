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
int parent[LEN];
int cArr[LEN];

void unionF(int a, int b)
{
    parent[b]=a;
    cArr[a]+=cArr[b];
}

int findP(int a)
{
    if(parent[a]==a) return a;
    parent[a]=findP(parent[a]);
    return parent[a];
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        cArr[i]=1;
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<n-1;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        pq.push({w,{a,b}});
    }
    ll res=0;
    while(!pq.empty())
    {
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        ll w=pq.top().first;
        pq.pop();
        int ap=findP(a);
        int bp=findP(b);
        if(ap>bp)
        {
            int c=a;
            a=b;
            b=c;
            c=ap;
            ap=bp;
            bp=c;
        }
        res+=w*cArr[ap]*cArr[bp];
        unionF(ap,bp);
    }
    cout<<res;
}