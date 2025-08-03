#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[1000][1000]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int dp[1000][1000]={0};
    dp[0][0]=arr[0][0];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][0]+arr[i][0];
    }
    for(int i=1;i<m;i++)
    {
        dp[0][i]=dp[0][i-1]+arr[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            int ps;
            if(dp[i-1][j]>dp[i][j-1]) ps=dp[i-1][j];
            else ps=dp[i][j-1];
            dp[i][j]=ps+arr[i][j];
        }
    }
    cout<<dp[n-1][m-1];
}