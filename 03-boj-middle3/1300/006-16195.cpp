#include <iostream>

#define LEN 1001
typedef long long ll;

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll dp[LEN][LEN]={0};
    ll MOD=1'000'000'009;
    dp[0][0]=1;
    for(int i=0;i<LEN-1;i++)
    {
        for(int j=0;j<LEN-1;j++)
        {
            if(dp[i][j]==0) continue;
            int next=i+1;
            while(next<LEN && next<=i+3)
            {
                dp[next][j+1]+=dp[i][j];
                dp[next][j+1]%=MOD;
                next++;
            }
        }
    }
    ll res[LEN][LEN];
    for(int i=0;i<LEN;i++)
    {
        ll sumV=0;
        for(int j=0;j<LEN;j++)
        {
            sumV+=dp[i][j];
            sumV%=MOD;
            res[i][j]=sumV;
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        cout<<res[n][m]<<"\n";
    }
}