#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    long long dp[90][2];
    for(int i=0;i<inputNum;i++)
    {
        if(i==0)
        {
            dp[0][0]=0;
            dp[0][1]=1;
            continue;
        }
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    std::cout<<dp[inputNum-1][0]+dp[inputNum-1][1]<<"\n";
    return 0;
}
