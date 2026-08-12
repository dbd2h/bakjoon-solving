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
#define MOD (ll)(1e9+7)

using namespace std;

ll inv[LEN];
ll fac[LEN];
vector<int> graph[LEN];
ll child[LEN]={0};

ll resArr[LEN];

void dfs(int cur, int p)
{
    for(auto&next : graph[cur])
    {
        if(next==p) continue;
        dfs(next,cur);
        child[cur]+=child[next];
    }
    child[cur]++;
}

void dfs2(int cur, int p, int n)
{
    if(cur!=1)
    {
        int c=1;
        for(auto &next : graph[cur])
        {
            if(next==p) continue;
            c+=child[next];
        }
        ll res=resArr[p];
        res*=child[cur];
        res%=MOD;
        res*=inv[n-c];
        res%=MOD;
        resArr[cur]=res;
    }   
    for(auto&next : graph[cur])
    {
        if(next==p) continue;
        dfs2(next,cur,n);
    }
}

int main()
{
    ll num=1;
    fac[1]=num;
    fac[0]=1;
    for(int i=2;i<LEN;i++)
    {
        num*=i;
        num%=MOD;
        fac[i]=num;
    }
    inv[1]=1;
    inv[0]=1;
    for(int i=2;i<LEN;i++)
    {
        ll mul=i;
        ll m=MOD-2;
        ll num=1;
        while(m)
        {
            if(m%2==1)
            {
                num*=mul;
                num%=MOD;
            }
            mul*=mul;
            mul%=MOD;
            m/=2;
        }
        inv[i]=num;
        inv[i]%=MOD;
    }

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0);
    ll res=1;
    res*=fac[n];
    for(int i=1;i<=n;i++)
    {
        res*=inv[child[i]];
        res%=MOD;
    }
    resArr[1]=res;
    dfs2(1,0,n);
    for(int i=1;i<=n;i++) cout<<resArr[i]<<"\n";
}