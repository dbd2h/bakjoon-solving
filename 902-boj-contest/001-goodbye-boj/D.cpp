#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

int cmp(pair<pair<int,int>,pair<int,int>> p1, pair<pair<int,int>,pair<int,int>> p2)
{
    if(p1.second.first==p2.second.first) return p1.second.second<p2.second.second;
    return p1.second.first<p2.second.first;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,pair<int,int>>> v;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        if(a>b)
        {
            int c=a;
            a=b;
            b=c;
        }
        
        v.push_back({{a,b},{w,i}});
    }
    sort(v.begin(),v.end(),cmp);
    int parent[100001];
    for(int i=0;i<=n;i++) parent[i]=-1;
    ll tot=0;
    int count=0;
    int idx1=-1;
    for(int i=0;i<m;i++)
    {
        int a=v[i].first.first;
        int b=v[i].first.second;
        int w=v[i].second.first;
        int idx=v[i].second.second;
        int ap=a;
        int bp=b;
        while(parent[ap]!=-1) ap=parent[ap];
        while(parent[bp]!=-1) bp=parent[bp];
        if(ap==bp) continue;
        count++;
        tot+=(ll) w;
        if(ap>bp)
        {
            int c=ap;
            ap=bp;
            bp=c;
            c=a;
            a=b;
            b=c;
        }
        bp=parent[b];
        while(b!=a)
        {
            parent[b]=ap;
            if(bp==-1) break;
            b=bp;
            bp=parent[bp];
        }
        if(count==n-1)
        {
            idx1=i;
            break;
        }
    }
    while(idx1+1!=m && v[idx1].second.first==v[idx1+1].second.first) idx1++;
    for(int i=0;i<=n;i++) parent[i]=-1;
    ll tot2=0;
    int count1=0;
    vector<int> resV;
    for(int i=idx1;i>=0;i--)
    {
        int a=v[i].first.first;
        int b=v[i].first.second;
        int w=v[i].second.first;
        int idx=v[i].second.second;
        int ap=a;
        int bp=b;
        while(parent[ap]!=-1) ap=parent[ap];
        while(parent[bp]!=-1) bp=parent[bp];
        if(ap==bp) continue;
        resV.push_back(idx+1);
        count1++;
        tot2+=(ll) w;
        if(ap>bp)
        {
            int c=ap;
            ap=bp;
            bp=c;
            c=a;
            a=b;
            b=c;
        }
        bp=parent[b];
        while(b!=a)
        {
            parent[b]=ap;
            if(bp==-1) break;
            b=bp;
            bp=parent[bp];
        }
        if(count1==n-1) break;
    }
    int len=resV.size();
    cout<<"NO\n";
    if(tot==tot2)
    {
        cout<<"NO\n";
        return 0;
    } 
    cout<<"YES\n";
    for(int i=0;i<len;i++)
    {
        cout<<resV[i]<<"\n";
    }
}