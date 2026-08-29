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
#define LEN 3001
#define INF (int)(1e9)

using namespace std;

int dp[LEN][LEN];

int cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first==p2.first) return p1.second>p2.second;
    return p1.first<p2.first;
}

int main()
{
    int n,t;
    cin>>n>>t;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<t;j++)
        {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    int res=0;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        v.push_back({n1,n2});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        int curT=v[i].first;
        int cur=v[i].second;
        for(int j=0;j<t;j++)
        {
            if(dp[i][j]==-1) continue;
            dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
            if(j+curT<t)
            {
                res=max(res,dp[i][j]+cur);
                dp[i+1][j+curT]=max(dp[i+1][j+curT],dp[i][j]+cur);
            }
            else res=max(res,dp[i][j]+cur);
        }
    }
    cout<<res;
}