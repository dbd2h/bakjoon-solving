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
#define LEN 151
#define INF (ll)(1e13)

using namespace std;

vector<pair<ll,bool>> v;
ll dp1[LEN][LEN];
ll dp2[LEN][LEN];

void program()
{
    int n,m;
    cin>>n>>m;
    v.clear();
    for(int i=0;i<=min(n+m,150);i++)
    {
        for(int j=0;j<=min(n+m,150);j++)
        {
            dp1[i][j]=0;
            dp2[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        ll num;
        cin>>num;
        v.push_back({num,0});
    }
    for(int i=0;i<m;i++)
    {
        ll num;
        cin>>num;
        v.push_back({num,1});
    }
    if(n+m>150)
    {
        cout<<0<<endl;
        return;
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n+m;i++)
    {
        for(int j=0;j<n+m;j++)
        {
            int l=j;
            int r=j+i;
            if(r>=n+m) break;
            if(i==1) dp2[l][r]=0;
            else
            {
                ll dpV=INF;
                for(int k=l;k<r;k++)
                {
                    dpV=min(dpV,dp1[l][k]+dp1[k+1][r]);
                }
                dp2[l][r]=dpV;
            }

            ll dpV=INF;
            for(int k=l;k<r;k++)
            {
                if(v[k].second==v[r].second) continue;
                if(dp1[l][k]>=INF) continue;
                ll cur=dp1[l][k]+(v[r].first-v[k].first)+dp2[k][r];
                dpV=min(dpV,cur);
            }
            dp1[l][r]=dpV;
        }
    }
    cout<<dp1[0][n+m-1]<<"\n";
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