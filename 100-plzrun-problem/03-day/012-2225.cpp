#include <iostream>

#define BILL 1'000'000'000

int main()
{
    int n,k;
    std::cin>>n>>k;
    int dp[n+1];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            {
                dp[j]=1;
                continue;
            }
            if(j!=0)
            {
                dp[j]=(dp[j]+dp[j-1])%BILL;
            }
        }
    }
    std::cout<<dp[n]<<"\n";
}