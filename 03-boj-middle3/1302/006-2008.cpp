#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    int ladder[501][101];
    int pArr[501];
    for(int i=1;i<=n;i++)
    {
        ladder[0][i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int p;
        cin>>p;
        pArr[i]=p;
        for(int j=1;j<=n;j++)
        {
            ladder[i][j]=ladder[i-1][j];
        }
        int cng=ladder[i][p];
        ladder[i][p]=ladder[i][p+1];
        ladder[i][p+1]=cng;
    }
    int dp[501][101];
    int dpZero=ladder[m][b];
    for(int i=m;i>=0;i--)
    {
        int curZeroI=0;
        for(int j=1;j<=n;j++)
        {
            if(ladder[i][j]==dpZero)
            {
                curZeroI=j;
                dp[i][curZeroI]=0;
                break;
            }
        }
        for(int j=curZeroI-1;j>=1;j--)
        {
            dp[i][j]=dp[i][j+1]+y;
            if(i==m) continue;
            int curP=pArr[i+1];
            int bef=dp[i+1][j];
            if(j==curP)
            {
                bef=dp[i+1][j+1];
                if(x+dp[i+1][j]<dp[i][j]) dp[i][j]=x+dp[i+1][j];
            } 
            else if(j==curP+1)
            {
                bef=dp[i+1][j-1];
                if(x+dp[i+1][j]<dp[i][j]) dp[i][j]=x+dp[i+1][j];
            } 
            if(dp[i][j]>bef) dp[i][j]=bef;
        }
        for(int j=curZeroI+1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1]+y;
            if(i==m) continue;
            int curP=pArr[i+1];
            int bef=dp[i+1][j];
            if(j==curP)
            {
                bef=dp[i+1][j+1];
                if(x+dp[i+1][j]<dp[i][j]) dp[i][j]=x+dp[i+1][j];
            } 
            else if(j==curP+1)
            {
                bef=dp[i+1][j-1];
                if(x+dp[i+1][j]<dp[i][j]) dp[i][j]=x+dp[i+1][j];
            } 
            if(dp[i][j]>bef) dp[i][j]=bef;
        }
    }
    cout<<dp[0][a];
}