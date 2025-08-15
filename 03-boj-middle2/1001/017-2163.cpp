#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int dp[301][301]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1 && j==1) continue;
            int minV=-1;
            for(int k=1;k<=j/2;k++)
            {
                int sumV=1;
                sumV+=(dp[i][k]+dp[i][j-k]);
                if(minV==-1 || minV>sumV) minV=sumV;
            }
            for(int k=1;k<=i/2;k++)
            {
                int sumV=1;
                sumV+=(dp[k][j]+dp[i-k][j]);
                if(minV==-1 || minV>sumV) minV=sumV;
            }
            dp[i][j]=minV;
        }
    }
    cout<<dp[n][m];
}