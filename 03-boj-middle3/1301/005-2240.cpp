#include <iostream>

using namespace std;

int main()
{
    int t,w;
    cin>>t>>w;
    int dp[1001][31][3];
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=30;j++)
        {
            dp[i][j][1]=-1;
            dp[i][j][2]=-1;
        }
    }
    dp[0][w][1]=0;
    int arr[1001];
    for(int i=1;i<=t;i++)
    {
        cin>>arr[i];
        for(int j=0;j<=w;j++)
        {
            for(int k=1;k<=2;k++)
            {
                if(dp[i-1][j][k]==-1) continue;
                if(dp[i-1][j][k]+(k==arr[i])>dp[i][j][k]) dp[i][j][k]=dp[i-1][j][k]+(k==arr[i]);
                if(j==0) continue;
                if(dp[i-1][j][k]+((k%2+1)==arr[i])>dp[i][j-1][k%2+1]) dp[i][j-1][k%2+1]=dp[i-1][j][k]+((k%2+1)==arr[i]);
            }
        }
    }
    int res=0;
    for(int i=0;i<=w;i++)
    {
        if(dp[t][i][1]>res) res=dp[t][i][1];
        if(dp[t][i][2]>res) res=dp[t][i][2];
    }
    cout<<res;
}