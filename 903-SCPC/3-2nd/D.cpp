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
ll down[LEN][2][2]; // max1{maxValue, idx}, max2{}
ll up[LEN];
ll wArr[LEN*2];
ll disArr[LEN*2];
int pArr[LEN*2];
int orderArr[LEN];
int par[LEN];
int countArr[LEN];

void dfs(int n)
{
    for(int i=n;i>=1;i--)
    {
        int cur=orderArr[i];
        for(auto&nextP : graph[cur])
        {
            int next=nextP.first;
            if(par[cur]==next) continue;
            int idx=nextP.second;
            ll w=wArr[idx];
            ll maxW=down[next][0][0]+w;
            if(down[cur][0][0]<maxW)
            {
                down[cur][1][0]=down[cur][0][0];
                down[cur][1][1]=down[cur][0][1];
                down[cur][0][0]=maxW;
                down[cur][0][1]=next;
            }
            else if(down[cur][1][0]<maxW)
            {
                down[cur][1][0]=maxW;
                down[cur][1][1]=next;
            }
            disArr[idx]=maxW;
        }
    }
}

void dfs2(int n)
{
    for(int i=1;i<=n;i++)
    {
        int cur=orderArr[i];
        for(auto&nextP : graph[cur])
        {
            ll maxV=up[cur];
            int next=nextP.first;
            int idx=nextP.second;
            int ridx=idx + (idx%2 ? -1 : 1);
            ll w=wArr[idx];
            if(next==par[cur]) continue;
            if(next==down[cur][0][1]) maxV=max(maxV,down[cur][1][0]);
            else maxV=max(maxV,down[cur][0][0]);
            up[next]=maxV+w;
            disArr[ridx]=maxV+w;
        }
    }
}

void dfs3(ll num, int n)
{
    
    for(int i=1;i<=n;i++) countArr[i]=1;
    for(int i=n;i>=1;i--)
    {
        int cur=orderArr[i];
        int c=0;
        for(auto&nextP : graph[cur])
        {
            int next=nextP.first;
            int idx=nextP.second;
            if(next==par[cur]) continue;
            if(disArr[idx]>num)
            {
                pArr[idx]=countArr[next];
                countArr[cur]+=countArr[next];
            }
            else pArr[idx]=0;
        }
    }
}

void dfs4(ll num, int n)
{
    for(int i=1;i<=n;i++)
    {
        int cur=orderArr[i];
        int nextC=1;
        for(auto&nextP : graph[cur])
        {
            int next=nextP.first;
            int idx=nextP.second;
            nextC+=pArr[idx];
        }
        for(auto&nextP : graph[cur])
        {
            int next=nextP.first;
            int idx=nextP.second;
            int ridx=idx + (idx%2 ? -1 : 1);
            if(next==par[cur]) continue;
            if(disArr[ridx]>num) pArr[ridx]=nextC-pArr[idx];
            else pArr[ridx]=0;
        }
    }
}

ll bs(ll l, ll r, int p, int n)
{
    if(l>r)
    {
        return r+1;
    }
    ll mid=(l+r)/2;
    dfs3(mid,n);
    dfs4(mid,n);
    ll minV=(1e18);
    for(int i=1;i<=n;i++)
    {
        ll cur=1;
        for(auto&nextP : graph[i])
        {
            int next=nextP.first;
            int idx=nextP.second;
            cur+=pArr[idx];
        }
        minV=min(cur,minV);
    }
    if(minV>p) return bs(mid+1,r,p,n);
    else return bs(l,mid-1,p,n);
}

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
        down[i][0][0]=down[i][0][1]=down[i][1][0]=down[i][1][1]=0;
        up[i]=0;    
        par[i]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        ll w;
        cin>>a>>b>>w;
        graph[a].push_back({b,2*i});
        graph[b].push_back({a,2*i+1});
        wArr[2*i]=w;
        wArr[2*i+1]=w;
    }
    
    orderArr[1]=1;
    int idx=2;
    for(int i=1;i<=n;i++)
    {
        int cur=orderArr[i];
        for(auto& nextP : graph[cur])
        {
            int next=nextP.first;
            if(par[cur]==next) continue;
            par[next]=cur;
            orderArr[idx]=next;
            idx++;
        }
    }
    int p;
    cin>>p;
    dfs(n);
    dfs2(n);
    cout<<bs(0,(1e12),p,n)<<endl;
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