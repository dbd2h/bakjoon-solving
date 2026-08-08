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
#define INF (ll)(1e14)

using namespace std;

vector<pair<ll,ll>> v;
ll res=INF;

int cmp(pair<ll,ll>p1, pair<ll,ll>p2)
{
    return p1.second<p2.second;
}

stack<pair<ll,int>> stLD,stLU,stRD,stRU;

void dfs(int n, int c, ll a, ll b, ll sumV)
{
    if(n==c)
    {
        ll tot=0;
        if(!stLD.empty()) tot+=stLD.top().first;
        if(!stRD.empty()) tot+=stRD.top().first;
        if(!stLU.empty()) tot+=stLU.top().first;
        if(!stRU.empty()) tot+=stRU.top().first;
        res=min(res,tot);
        return;
    }
    if(res<=sumV) return;
    pair<ll,ll> &cur=v[c];
    if(!stLU.empty() && v[stLU.top().second].first>cur.first)
    {
        dfs(n,c+1,a,b,sumV);
        return;
    } 
    if(!stRU.empty() && v[stRU.top().second].first<cur.first)
    {
        dfs(n,c+1,a,b,sumV);
        return;
    } 
    stack<pair<ll,int>> stKeep;

    // stLD
    while(!stLD.empty() && v[stLD.top().second].first<cur.first)
    {
        stKeep.push(stLD.top());
        stLD.pop();
    }
    ll inc=0;
    if(stLD.empty())
    {
        inc=cur.first*cur.second;
        stLD.push({inc,c});
    } 
    else
    {
        inc=(cur.second-v[stLD.top().second].second)*cur.first;
        stLD.push({stLD.top().first+inc,c});
    } 
    dfs(n,c+1,a,b,sumV+inc);
    stLD.pop();
    while(!stKeep.empty())
    {
        stLD.push(stKeep.top());
        stKeep.pop();
    }
    // stRD
    while(!stRD.empty() && v[stRD.top().second].first>cur.first)
    {
        stKeep.push(stRD.top());
        stRD.pop();
    }
    if(stRD.empty())
    {
        inc=(a-cur.first)*cur.second;
        stRD.push({inc,c});
    } 
    else
    {
        inc=(cur.second-v[stRD.top().second].second)*(a-cur.first);
        stRD.push({stRD.top().first+inc,c});
    } 
    dfs(n,c+1,a,b,sumV+inc);
    stRD.pop();
    while(!stKeep.empty())
    {
        stRD.push(stKeep.top());
        stKeep.pop();
    }
    // stLU
    if(stLU.empty())
    {
        inc=(b-cur.second)*cur.first;
        stLU.push({inc,c});
    } 
    else
    {
        inc=(b-cur.second)*(cur.first-v[stLU.top().second].first);
        stLU.push({stLU.top().first+inc,c});
    } 
    dfs(n,c+1,a,b,sumV+inc);
    stLU.pop();
    // stRU
    if(stRU.empty())
    {
        inc=(b-cur.second)*(a-cur.first);
        stRU.push({inc,c});
    } 
    else
    {
        inc=(b-cur.second)*(v[stRU.top().second].first-cur.first);
        stRU.push({stRU.top().first+inc,c});
    } 
    dfs(n,c+1,a,b,sumV+inc);
    stRU.pop();
}

void program()
{
    ll a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    res=INF;
    v.clear();
    stLD=stack<pair<ll,int>>();
    stLU=stack<pair<ll,int>>();
    stRD=stack<pair<ll,int>>();
    stRU=stack<pair<ll,int>>();
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    if(n>45)
    {
        cout<<0<<endl;
        return;
    }
    sort(v.begin(),v.end(),cmp);
    dfs(n,0,a,b,0);
    cout<<a*b-res<<endl;

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}