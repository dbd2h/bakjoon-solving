#include <iostream>
#define BILLION 1000000000


int main()
{
    int inpunNum;
    std::cin>>inpunNum;
    long long dp[100][10];
    dp[0][0]=0;
    for(int i=1;i<10;i++)
    {
        dp[0][i]=1;
    }
    for(int i=1;i<inpunNum;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j+1];
            }
            else if(j==9)
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=(dp[i-1][j+1]+dp[i-1][j-1])%BILLION;
            }
        }
    }
    long long total=0;
    for(int i=0;i<10;i++)
    {
        total+=dp[inpunNum-1][i];
    }
    std::cout<<total%BILLION<<"\n";
}

// dp[4][1]=dp[3][0]+dp[3][2]