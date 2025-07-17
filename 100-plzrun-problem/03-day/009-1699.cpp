#include <iostream>

int multi(int num)
{
    return num*num;
}

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int dp[100001];
    dp[0]=0;
    int multiStd=0;
    int multiGauss=1;
    for(int i=1;i<=inputNum;i++)
    {
        multiStd++;
        int min=100000;
        for(int j=1;j<=multiGauss;j++)
        {
            int index=i-multi(j);
            if(min>dp[index]+1)
            {
                min=dp[index]+1;
            }
        }
        dp[i]=min;
        if(multiStd==multiGauss*2+1)
        {
            multiStd=0;
            multiGauss++;
        }
    }
    std::cout<<dp[inputNum]<<"\n";
    return 0;
}