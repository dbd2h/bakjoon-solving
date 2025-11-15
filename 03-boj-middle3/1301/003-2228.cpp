#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int dp[51][100]={0};
    for(int i=1;i<=m;i++)
    {
        for(int j=i*2-2;j<n;j++)
        {
            if(i==1)
            {
                dp[i][j]=arr[j];
                if(j!=0 && dp[i][j-1]>0) dp[i][j]=dp[i][j-1]+arr[j];
                continue;
            }
            if(j==i*2-2)
            {
                dp[i][j]=arr[j]+dp[i-1][j-2];
                continue;
            }
            dp[i][j]=dp[i][j-1]+arr[j];
            for(int k=i*2-4;k<=j-2;k++)
            {
                if(dp[i-1][k]+arr[j]>dp[i][j]) dp[i][j]=dp[i-1][k]+arr[j];
            }
        }
    }
    int res=dp[m][n-1];
    for(int i=m*2-2;i<n;i++)
    {
        if(res<dp[m][i]) res=dp[m][i];
    }
    cout<<res;
}