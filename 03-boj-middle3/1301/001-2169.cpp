#include <iostream>
#include <memory.h>

#define LEN 1000

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[LEN][LEN];
    int dp[LEN][LEN];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            dp[i][j]=-1e9;
        }
    }
    int totV=0;
    for(int i=0;i<m;i++)
    {   
        totV+=arr[0][i];
        dp[0][i]=totV;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int cur=dp[i][j]+arr[i+1][j];
            if(dp[i+1][j]<cur) dp[i+1][j]=cur;
            int l=j-1;
            int r=j+1;
            int left=cur;
            while(l>=0)
            {
                left+=arr[i+1][l];
                if(dp[i+1][l]<left) dp[i+1][l]=left;
                l--;
            }
            int right=cur;
            while(r<m)
            {
                right+=arr[i+1][r];
                if(dp[i+1][r]<right) dp[i+1][r]=right;
                r++;
            }
        }
    }
    cout<<dp[n-1][m-1];
}