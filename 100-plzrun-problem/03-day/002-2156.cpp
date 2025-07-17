#include <iostream>

long long max(long long num1, long long num2, long long num3)
{
    if(num1>num2)
    {
        if(num1>num3)
        {
            return num1;
        }
        else
        {
            return num3;
        }
    }
    if(num2<num3)
    {
        return num3;
    }
    else
    {
        return num2;
    }
}

int main()
{
    long long amount;
    std::cin>>amount;
    long long wine[amount];
    long long dp[amount];
    for(int i=0;i<amount;i++)
    {
        std::cin>>wine[i];
    }
    for(int i=0;i<amount;i++)
    {
        int dp1,dp2,dp3;
        dp1=0;
        dp2=0;
        dp3=0;
        if(i==0)
        {
            dp1=wine[i];
        }
        else if(i==1)
        {
            dp1=dp[i-1]+wine[i];
        }
        else if(i==2)
        {
            dp1=dp[i-2]+wine[i-1];
            dp2=dp[i-2]+wine[i];
            dp3=wine[i-1]+wine[i];
        }
        else
        {
            dp1=dp[i-3]+wine[i-1]+wine[i];
            dp2=dp[i-2]+wine[i];
            dp3=dp[i-1];
        }
        dp[i]=max(dp1,dp2,dp3);
    }
    std::cout<<dp[amount-1]<<"\n";
    return 0;
}