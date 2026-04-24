#include <iostream>

using namespace std;

int main()
{
    int c,n;
    cin>>c>>n;
    int dp[1101];
    for(int i=0;i<=1100;i++) dp[i]=-1;
    dp[0]=0;
    int promotion[20][2];
    for(int i=0;i<n;i++)
    {
        cin>>promotion[i][0]>>promotion[i][1];
    }
    for(int i=0;i<c;i++)
    {
        if(dp[i]==-1) continue;
        for(int j=0;j<n;j++)
        {
            int nextI=i+promotion[j][1];
            int nextV=dp[i]+promotion[j][0];
            if(dp[nextI]==-1 || dp[nextI]>nextV) dp[nextI]=nextV;
        }
    }
    int res=1e9;
    for(int i=c;i<=c+100;i++)
    {
        if(dp[i]==-1) continue;
        if(res>dp[i]) res=dp[i];
    }
    cout<<res;
}