#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int numArr[inputNum+1];
    int dp[inputNum+1];
    dp[0]=0;
    for(int i=1;i<=inputNum;i++)
    {
        std::cin>>numArr[i];
        int max=0;
        for(int j=1;j<=i;j++)
        {
            if(max<dp[i-j]+numArr[j])
            {
                max=dp[i-j]+numArr[j];
            }
        }
        dp[i]=max;
    }
    std::cout<<dp[inputNum]<<"\n";
    return 0;
}