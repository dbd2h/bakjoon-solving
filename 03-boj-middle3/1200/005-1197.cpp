#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int parent[10001]={0};

int findParent(int cur)
{
    if(parent[cur]==0) return cur;
    int p=findParent(parent[cur]);
    parent[cur]=p;
    return p;
}

bool compare(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2)
{
    if(p1.second==p2.second) return false;
    return p1.second<p2.second;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<pair<int,int>,int>> edgeV;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edgeV.push_back({{a,b},c});
    }
    sort(edgeV.begin(),edgeV.end(),compare);
    ll res=0;
    int count=0;
    for(int i=0;i<e;i++)
    {
        pair<pair<int,int>,int> p=edgeV[i];
        int a=p.first.first;
        int b=p.first.second;
        int c=p.second;
        int ap=findParent(a);
        int bp=findParent(b);
        if(ap==bp) continue;
        parent[bp]=ap;
        res+=(ll) c;
        count++;
        if(count==v-1) break;
    }
    cout<<res;
}