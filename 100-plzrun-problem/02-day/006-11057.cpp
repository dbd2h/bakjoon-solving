#include <iostream>

int main()
{
    int inputNum;
    std::cin>>inputNum;
    int dp[1000][10];

    for(int i=0;i<inputNum;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(i==0)
            {
                dp[i][j]=1;
                continue;
            }
            int total=0;
            for(int k=j;k<10;k++)
            {
                total+=dp[i-1][k];
            }
            dp[i][j]=total%10007;
        }
    }
    int total=0;
    for(int i=0;i<10;i++)
    {
        total+=dp[inputNum-1][i];
    }
    std::cout<<total%10007<<"\n";
    return 0;
}