#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long dp[101]={0};
    for(int i=1;i<=n;i++)
    {
        dp[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        long long mul=2;
        for(int j=i+3;j<=n;j++)
        {
            if(dp[j]<dp[i]*mul) dp[j]=dp[i]*mul;
            mul++;
        }
    }
    cout<<dp[n];
}