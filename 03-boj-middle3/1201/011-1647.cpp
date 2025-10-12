#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    return p1.first<p2.first;
}

int findParent(int parent[], int cur)
{
    if(parent[cur]==0) return cur;
    return findParent(parent,parent[cur]);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b)
        {
            int change=a;
            a=b;
            b=change;
        }
        v.push_back({c,{a,b}});
    }
    sort(v.begin(),v.end(),cmp);
    int parent[100001]={0};
    int c=0;
    int res=0;
    for(int i=0;i<m;i++)
    {
        if(c==n-2) break;
        int a=v[i].second.first;
        int b=v[i].second.second;
        int w=v[i].first;
        int ap=findParent(parent,a);
        int bp=findParent(parent,b);
        if(ap==bp) continue;
        res+=w;
        c++;
        while(b)
        {
            int next=parent[b];
            parent[b]=ap;
            b=next;
        }
        if(c==n-2) break;
    }
    cout<<res;
}