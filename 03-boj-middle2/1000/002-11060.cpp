#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[1000]={0};
    int dp[1000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i!=0 && dp[i]==0) continue;
        for(int j=1;j<=arr[i];j++)
        {
            if(i+j>=n) break;
            if(dp[i+j]==0 || dp[i+j]>dp[i]+1) dp[i+j]=dp[i]+1;
        }
    }
    if(n==1) cout<<0;
    else if(!dp[n-1]) cout<<-1;
    else cout<<dp[n-1];
}