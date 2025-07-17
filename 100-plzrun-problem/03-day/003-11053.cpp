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
        int max=1;
        for(int j=i-1;j>=0;j--)
        {
            if(numArr[i]>numArr[j]&&max<dp[j]+1)
            {
                max=dp[j]+1;
            }
        }
        dp[i]=max;
        if(finMax<max)
        {
            finMax=max;
        }
    }

    std::cout<<finMax<<"\n";
}

// 1 2 3 6 4 5 7