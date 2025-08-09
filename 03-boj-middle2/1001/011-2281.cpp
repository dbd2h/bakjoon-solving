#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int dp[1000][1000][2]={0};
    int arr[1000]={0};
    int plus=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0)
        {
            dp[0][0][1]=arr[i];
            continue;
        } 
        if(dp[0][i-1][1]!=0 && dp[0][i-1][1]+arr[i]+1<=m) dp[0][i][1]=dp[0][i-1][1]+arr[i]+1;
    }
    bool isF=false;
    int start=0;
    int res=-1;
    for(int i=0;i<n;i++)
    {
        int bef[1000][2]={0};
        int s=0;
        int len=0;
        for(int j=start;j<n;j++)
        {
            if(res!=-1)
            {
                if(dp[i][j][0]>res)
                {
                    start++;
                    continue;
                }
            }
            for(int k=s;k<len;k++)
            {
                bef[k][1]+=(1+arr[j]);
                if(bef[k][1]>m) s++;
                else if(j+1==n)
                {
                    if(res==-1 || res>bef[k][0]) res=bef[k][0];
                }
            }
            if(dp[i][j][1]!=0)
            {
                bef[len][0]=dp[i][j][0];
                bef[len][1]=dp[i][j][1];
                len++;
            }
            if(s==len) break;
            int minV=-1;
            for(int k=s;k<len;k++)
            {
                if(minV==-1 || minV>(m-bef[k][1])*(m-bef[k][1])+bef[k][0]) minV=(m-bef[k][1])*(m-bef[k][1])+bef[k][0];
            }
            if(j+1!=n && minV!=-1)
            {
                dp[i+1][j+1][0]=minV;
                dp[i+1][j+1][1]=arr[j+1];
            }
        }
        start++;
    }
    for(int i=0;i<n;i++)
    {
        if(dp[i][n-1][0]!=0 && dp[i][n-1][0]<res) res=dp[i][n-1][0];
    }
    cout<<res;
}