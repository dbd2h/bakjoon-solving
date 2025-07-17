#include <iostream>

int max(int num1, int num2)
{
    if(num1>num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int numArr[inputNum];
    int dp[inputNum];
    for(int i=0;i<inputNum;i++)
    {
        int dp1,dp2;
        std::cin>>numArr[i];
        dp1=0;
        dp2=0;
        if(i==0)
        {
            dp1=numArr[i];
        }
        else if(i==1)
        {
            dp1=numArr[i-1]+numArr[i];
        }
        else if(i==2)
        {
            dp1=numArr[i-2]+numArr[i];
            dp2=numArr[i-1]+numArr[i];
        }
        else
        {
            dp1=dp[i-3]+numArr[i-1]+numArr[i];
            dp2=dp[i-2]+numArr[i];
        }
        dp[i]=max(dp1,dp2);
    }
    std::cout<<dp[inputNum-1]<<"\n";
    return 0;
}