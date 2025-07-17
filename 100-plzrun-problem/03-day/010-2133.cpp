#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    if(inputNum%2==1)
    {
        std::cout<<0<<"\n";
        return 0;
    }
    inputNum/=2;
    int dp[16];
    dp[0]=1;

    for(int i=1;i<=inputNum;i++)
    {
        int total=0;
        for(int j=i;j>0;j--)
        {
            if(j==1)
            {
                total+=dp[i-j]*3;
                break;
            }
            total+=dp[i-j]*2;
        }
        dp[i]=total;
    }
    std::cout<<dp[inputNum]<<"\n";
}