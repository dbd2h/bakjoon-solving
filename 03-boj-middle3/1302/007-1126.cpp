#include <iostream>

#define LEN 500001

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[51];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int dp[51][LEN];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<LEN;j++)
        {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<LEN;j++)
        {
            if(dp[i][j]==-1) continue;
            int cur=arr[i+1];
            int high=dp[i][j];
            int low=high-j;
            if(dp[i+1][j]<high) dp[i+1][j]=high;
            if(dp[i+1][j+cur]<high+cur) dp[i+1][j+cur]=high+cur;
            low+=cur;
            if(high<low)
            {
                int cng=low;
                low=high;
                high=cng;
            }
            if(dp[i+1][high-low]<high) dp[i+1][high-low]=high;
        }
    }
    int res=-1;
    for(int i=1;i<=n;i++)
    {
        if(dp[i][0]==0) continue;
        if(res<dp[i][0]) res=dp[i][0];
    }
    cout<<res;
}