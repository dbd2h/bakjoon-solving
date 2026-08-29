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

using namespace std;

vector<pair<ll,pair<ll,ll>>> v; // v, w, k

int cmp(pair<ll,pair<ll,ll>> p1, pair<ll,pair<ll,ll>> p2)
{
    if(p1.first*(6/p1.second.first)==p2.first*(6/p2.second.first)) return p1.second.first>p2.second.first;
    return p1.first*(6/p1.second.first)> p2.first*(6/p2.second.first);
}

int main()
{
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v.push_back({b,{a,c}});
    }
    sort(v.begin(),v.end(),cmp);
    ll res=0;
    for(auto&p : v)
    {
        ll k=p.second.second;
        ll value=p.first;
        ll w=p.second.first;
        if(w*k<c-4)
        {
            res+=value*k;
            c-=w*k;
            continue;
        }
        c-=(c-4)/w;
        res+=value*((c-4)/w);
        k-=(c-4)/w;
        if(c>4 && k>=1)
        {
            
        }
    }
}