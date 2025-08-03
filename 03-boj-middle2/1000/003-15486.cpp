#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int dp[1500001]={0};
    for(int i=0;i<n;i++)
    {
        int t,p;
        cin>>t>>p;
        if(dp[i+1]<dp[i]) dp[i+1]=dp[i];
        if(i+t>n) continue;
        if(dp[i+t]<dp[i]+p) dp[i+t]=dp[i]+p;
        
    }
    cout<<dp[n];
}