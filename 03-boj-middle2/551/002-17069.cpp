#include <iostream>

using namespace std;

int arr[32][32]={0};

long long dp[32][32][3]={0}; // 가, 세, 대

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    dp[0][1][0]=1;
    for(int i=2;i<n;i++)
    {
        if(arr[0][i]==1) break;
        dp[0][i][0]=dp[0][i-1][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=2;j<n;j++)
        {
            if(arr[i][j]==1) continue;
            //가로
            dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][2];
            //세로
            dp[i][j][1]=dp[i-1][j][1]+dp[i-1][j][2];
            //대각선
            if(arr[i-1][j]==1 || arr[i][j-1]==1) continue;
            dp[i][j][2]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
        }
    }
    cout<<dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2];
}