#include <iostream>
#include <queue>

#define LEN 10001

using namespace std;

priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
int parent[LEN];
int sz[LEN];

int find(int x)
{
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

bool unite(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return false;
    if(sz[a]<sz[b])
    {
        int c=a;
        a=b;
        b=c;
    }
    parent[b]=a;
    sz[a]+=sz[b];
}

int kruskal(int n)
{
    int len=0;
    int res=0;
    while(!pq.empty())
    {
        int w=pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        if(!unite(a,b)) continue;
        len++;
        res+=w;
        if(len==n-1) break;
    }
    if(len<n-1) return -1;
    else return res;
}


int main()
{
    int n,e;
    cin>>n>>e; // node가 1부터 n까지, edge가 e개
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        sz[i]=1;
    } 
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({c,{a,b}});
    }
    cout<<kruskal(n); // MST의 가중치 합을 구하는 문제. TREE가 만들어지지 않으면 -1
}