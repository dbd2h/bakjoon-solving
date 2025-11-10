#include <iostream>

#define LEN 100001
typedef long long ll;

using namespace std;

int main()
{
    ll dp[11][LEN]={0};
    ll MOD=1'000'000'007;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        ll totV=0;
        for(int j=1;j<=k;j++)
        {
            totV+=dp[i-1][j];
            totV%=MOD;
        }
        for(int j=1;j<=k;j++) dp[i][j]=totV;
        for(int j=1;j<=k;j++)
        {
            int idx=j;
            idx+=j;
            while(idx<=k)
            {
                dp[i][idx]-=dp[i-1][j];
                dp[i][idx]+=MOD;
                dp[i][idx]%=MOD;
                idx+=j;
            }
        }
    }
    ll res=0;
    for(int i=1;i<=k;i++)
    {
        res+=dp[n][i];
        res%=MOD;
    }
    cout<<res;
}