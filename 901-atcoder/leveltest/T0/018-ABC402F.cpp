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

ll rem[41];
ll arr[21][21];

int main()
{
    int n;
    ll m;
    cin>>n>>m;
    rem[0]=1;
    for(int i=1;i<=40;i++)
    {
        rem[i]=rem[i-1]*10;
        rem[i]%=m;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            int idx=n*2-i-j;
            arr[i][j]*=rem[idx];
            arr[i][j]%=m;
        }
    }
    queue<pair<ll,pair<int,int>>> q;
    q.push({arr[1][1],{1,1}});
    vector<ll> v[21];
    while(!q.empty())
    {
        ll cur=q.front().first;
        int down=q.front().second.first;
        int right=q.front().second.second;
        q.pop();
        if(down+right+1==n+1)
        {
            v[down].push_back((cur+arr[down][right+1])%m);
            v[down+1].push_back((cur+arr[down+1][right])%m);
            continue;
        }
        q.push({(cur+arr[down][right+1])%m,{down,right+1}});
        q.push({(cur+arr[down+1][right])%m,{down+1,right}});
    }
    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
    q.push({arr[n][n],{n,n}});
    ll res=0;
    while(!q.empty())
    {
        ll cur=q.front().first;
        int down=q.front().second.first;
        int right=q.front().second.second;
        q.pop();
        if(down+right-1==n+1)
        {
            int l=0;
            int r=v[down].size()-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(v[down][mid]+cur<m) l=mid+1;
                else r=mid-1;
            }
            if(l==0) res=max(res,(cur+v[down][v[down].size()-1])%m);
            else res=max(res,(cur+v[down][l-1])%m);
            l=0;
            r=v[down-1].size()-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(v[down-1][mid]+cur<m) l=mid+1;
                else r=mid-1;
            }
            if(l==0) res=max(res,(cur+v[down-1][v[down-1].size()-1])%m);
            else res=max(res,(cur+v[down-1][l-1])%m);
            continue;
        }
        q.push({(cur+arr[down][right-1])%m,{down,right-1}});
        q.push({(cur+arr[down-1][right])%m,{down-1,right}});
    }
    cout<<res;
}