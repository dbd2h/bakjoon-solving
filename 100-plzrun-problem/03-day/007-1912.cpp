#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int numArr[inputNum];
    int dp[inputNum];
    std::cin>>numArr[0];
    dp[0]=numArr[0];
    int max=numArr[0];
    for(int i=1;i<inputNum;i++)
    {
        std::cin>>numArr[i];
        if(dp[i-1]>0)
        {
            dp[i]=numArr[i]+dp[i-1];
        }
        else
        {
            dp[i]=numArr[i];
        }
        if(max<dp[i])
        {
            max=dp[i];
        }
    }
    std::cout<<max<<"\n";
    return 0;
}