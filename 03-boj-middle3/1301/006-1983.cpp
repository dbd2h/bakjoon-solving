#include <iostream>
#include <vector>

#define LEN 401

using namespace std;

int main()
{
    int n;
    cin>>n;
    int upZero=0;
    int downZero=0;
    vector<int> arr[2];
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        if(num==0) upZero++;
        else arr[0].push_back(num);
    }
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        if(num==0) downZero++;
        else arr[1].push_back(num);
    }
    int dp[LEN][LEN][LEN];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=upZero;j++)
        {
            for(int k=0;k<=downZero;k++)
            {
                dp[i][j][k]=-1e9;
            }
        }
    }
    
    dp[0][0][0]=0;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=upZero;j++)
        {
            for(int k=0;k<=downZero;k++)
            {
                if(dp[i][j][k]==-1e9) continue;
                if(n-upZero>=i+1-j && n-downZero>=i+1-k && dp[i+1][j][k]<dp[i][j][k]+arr[0][i-j]*arr[1][i-k])dp[i+1][j][k]=dp[i][j][k]+arr[0][i-j]*arr[1][i-k];
                if(n-downZero>=i+1-k && j!=upZero && dp[i+1][j+1][k]<dp[i][j][k]) dp[i+1][j+1][k]=dp[i][j][k];
                if(n-upZero>=i+1-j && k!=downZero && dp[i+1][j][k+1]<dp[i][j][k]) dp[i+1][j][k+1]=dp[i][j][k];
                if(j!=upZero && k!=downZero && dp[i+1][j+1][k+1]<dp[i][j][k]) dp[i+1][j+1][k+1]=dp[i][j][k];
            }
        }
    }
    cout<<dp[n][upZero][downZero];
}