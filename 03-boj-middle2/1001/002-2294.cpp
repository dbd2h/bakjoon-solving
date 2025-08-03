#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int dp[10001]={0};
    for(int i=0;i<n;i++)
    {
        int coin;
        cin>>coin;
        for(int j=0;j<=k;j++)
        {
            if(j+coin>k) break;
            if(j!=0 && dp[j]==0) continue;
            if(dp[j+coin]==0 || dp[j+coin]>dp[j]+1) dp[j+coin]=dp[j]+1;
        }
    }
    if(!dp[k]) dp[k]=-1;
    cout<<dp[k];
}