#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    for(int count=0;count<inputNum;count++)
    {
        int t;
        std::cin>>t;
        long long dp[100];
        for(int i=0;i<t;i++)
        {
            if(i<3)
            {
                dp[i]=1;
                continue;
            }
            else if(i<5)
            {
                dp[i]=2;
                continue;
            }
            dp[i]=dp[i-1]+dp[i-5];
        }
        std::cout<<dp[t-1]<<"\n";
    }
    
    return 0;
}