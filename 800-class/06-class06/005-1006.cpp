#include <iostream>

using namespace std;

int minF(int n1, int n2)
{
    if(n1>n2) return n2;
    else return n1;
}

void dpMaker(int arr[2][10000], int dp[10000][3], int n, int w)
{
    for(int i=2;i<n;i++)
    {
        dp[i][0]=dp[i-1][0]+2;
        dp[i][1]=minF(dp[i-1][2]+2,dp[i-1][0]+1);
        dp[i][2]=minF(dp[i-1][1]+2,dp[i-1][0]+1);
        int row1=arr[0][i]+arr[0][i-1];
        int row2=arr[1][i]+arr[1][i-1];
        int col1=arr[0][i]+arr[1][i];
        int col2=arr[0][i-1]+arr[1][i-1];
        if(col1<=w) dp[i][0]=minF(dp[i][0],dp[i-1][0]+1);
        int block2=4;
        if(row1<=w && row2<=w || col1<=w && col2<=w) block2=2;
        else if(row1>w && row2>w && col1>w && col2>w) block2=4;
        else block2=3;
        if(i==1) dp[i][0]=minF(dp[i][0],block2);
        else dp[i][0]=minF(dp[i][0],dp[i-2][0]+block2);
        if(row1<=w)
        {
            dp[i][0]=minF(dp[i][0],dp[i-1][2]+2);
            dp[i][1]=minF(dp[i][1],dp[i-1][2]+1);
        } 
        if(row2<=w)
        {
            dp[i][0]=minF(dp[i][0],dp[i-1][1]+2);
            dp[i][2]=minF(dp[i][2],dp[i-1][1]+1);
        }
    }
}

void problem()
{
    int n,w;
    cin>>n>>w;
    int arr[2][10000];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int dp1[10000][3]; // both full, up full, down full
    dp1[0][0]=2;
    dp1[0][1]=1;
    dp1[0][2]=1;
    int res=20000;
    if(arr[0][0]+arr[1][0]<=w) dp1[0][0]=1;
    if(n==1)
    {
        cout<<dp1[0][0]<<"\n";
        return;
    }
    int row1=arr[0][1]+arr[0][0];
    int row2=arr[1][1]+arr[1][0];
    int col1=arr[0][1]+arr[1][1];
    int col2=arr[0][0]+arr[1][0];
    dp1[1][1]=minF(dp1[0][0]+1,row1<=w ? 2:3);
    dp1[1][2]=minF(dp1[0][0]+1,row2<=w ? 2:3);
    if(row1<=w && row2<=w || col1<=w && col2<=w) dp1[1][0]=2;
    else if(row1>w && row2>w && col1>w && col2>w) dp1[1][0]=4;
    else dp1[1][0]=3;
    if(n==2)
    {
        cout<<dp1[1][0]<<"\n";
        return;
    }
    dpMaker(arr,dp1,n,w);
    if(dp1[n-1][0]<res)res=dp1[n-1][0];
    if(arr[0][0]+arr[0][n-1]<=w)
    {
        int dp2[10000][3]; // both full, up full, down full
        dp2[0][0]=2;
        dp2[0][1]=1;
        dp2[0][2]=1;
        dp2[1][1]=3;
        dp2[1][2]=minF(dp2[0][0]+1,row2<=w ? 2:3);
        if(row2<=w || col1<=w) dp2[1][0]=3;
        else dp2[1][0]=4;

        dpMaker(arr,dp2,n,w);
        if(dp2[n-1][2]<res)res=dp2[n-1][2];
    }
    if(arr[1][0]+arr[1][n-1]<=w)
    {
        int dp3[10000][3]; // both full, up full, down full
        dp3[0][0]=2;
        dp3[0][1]=1;
        dp3[0][2]=1;
        dp3[1][1]=minF(dp3[0][0]+1,row1<=w ? 2:3);
        dp3[1][2]=3;
        if(row1<=w || col1<=w) dp3[1][0]=3;
        else dp3[1][0]=4;

        dpMaker(arr,dp3,n,w);
        if(dp3[n-1][1]<res)res=dp3[n-1][1];
    }
    if(arr[0][0]+arr[0][n-1]<=w && arr[1][0]+arr[1][n-1]<=w)
    {   
        int dp4[10000][3]; // both full, up full, down full
        dp4[0][0]=2;
        dp4[0][1]=1;
        dp4[0][2]=1;
        dp4[1][1]=3;
        dp4[1][2]=3;
        if(col1<=w) dp4[1][0]=3;
        else dp4[1][0]=4;
        
        dpMaker(arr,dp4,n,w);
        if(dp4[n-2][0]<res)res=dp4[n-2][0];
    }
    cout<<res<<"\n";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}