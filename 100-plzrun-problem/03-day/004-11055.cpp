#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int numArr[inputNum];
    int dp[inputNum];
    int finMax=0;
    for(int i=0;i<inputNum;i++)
    {
        std::cin>>numArr[i];
        int max=numArr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(numArr[i]>numArr[j]&&max<dp[j]+numArr[i])
            {
                max=dp[j]+numArr[i];
            }
        }
        dp[i]=max;
        if(max>finMax)
        {
            finMax=max;
        }
    }
    std::cout<<finMax<<"\n";
}