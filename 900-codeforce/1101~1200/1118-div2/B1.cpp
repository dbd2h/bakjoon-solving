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
#define LEN 21

using namespace std;

ll bit[LEN]={0};
ll resArr[LEN]={0};

void dfs(int m, int b, int c)
{
    if(c>0)
    {
        for(int i=1;i<=m;i++)
        {
            resArr[c]=max(resArr[c],bit[i]);
        }
    }
    if(b==0) return;
    int cur=1;
    while(cur<=b)
    {
        vector<pair<ll,ll>> chV;
        for(int i=cur+1;i<=m;i++)
        {
            if(bit[i]==0) continue;
            chV.push_back({i,bit[i]});
            bit[i-cur]+=bit[i];
            bit[cur]+=bit[i];
            bit[i]=0;
        }
        dfs(m,b/2,c+1);
        for(auto&p : chV)
        {
            ll num=p.first;
            ll co=p.second;
            bit[num]+=co;
            bit[num-cur]-=co;
            bit[cur]-=co;
        }
        cur*=2;
    }
}

void dfs2(int m, int c, int div)
{
    if(c>0)
    {
        for(int i=1;i<=m;i++)
        {
            resArr[c]=max(resArr[c],bit[i]);
        }
    }
    if(div%2==1) return;
    if(c==0)
    {
        int tot=0;
        for(int i=1;i<=m;i++)
        {
            tot+=bit[i];
            if(i%2==1 || bit[i]==0) continue;
            if(bit[i]*2+bit[i/2]<=tot-bit[i]) continue;
            int cur=i/2;
            vector<pair<ll,ll>> chV;
            for(int j=cur+1;j<=m;j++)
            {
                if(bit[j]==0) continue;
                chV.push_back({j,bit[j]});
                bit[j-cur]+=bit[j];
                bit[cur]+=bit[j];
                bit[j]=0;
            }
            dfs2(m,c+1,cur);
            for(auto&p : chV)
            {
                ll num=p.first;
                ll co=p.second;
                bit[num]+=co;
                bit[num-cur]-=co;
                bit[cur]-=co;
            }
        }
        return;
    }
    int cur=div/2;
    vector<pair<ll,ll>> chV;
    for(int i=cur+1;i<=m;i++)
    {
        if(bit[i]==0) continue;
        chV.push_back({i,bit[i]});
        bit[i-cur]+=bit[i];
        bit[cur]+=bit[i];
        bit[i]=0;
    }
    dfs2(m,c+1,cur);
    for(auto&p : chV)
    {
        ll num=p.first;
        ll co=p.second;
        bit[num]+=co;
        bit[num-cur]-=co;
        bit[cur]-=co;
    }
}

void program()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        bit[i]=0;
        resArr[i]=0;
    } 

    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        bit[num]++;
    }
    int b=m;
    while(b-(b&-b)) b-=(b&-b);
    dfs(m,b,0);
    dfs2(m,0,0);
    cout<<resArr[1]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}