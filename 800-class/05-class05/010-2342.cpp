#include <iostream>
#include <vector>
#define MAX_LEN 100001

using namespace std;

int main()
{
    int dp[MAX_LEN][5][5];
    for(int i=0;i<MAX_LEN;i++)
    {
        for(int j=0;j<=4;j++)
        {
            for(int k=0;k<=4;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    dp[0][0][0]=0;
    vector<int> inputV;
    int num;
    cin>>num;
    while(num)
    {
        inputV.push_back(num);
        cin>>num;
    }
    int len=inputV.size();
    for(int i=0;i<len;i++)
    {
        int cur=inputV[i];
        for(int l=0;l<=4;l++)
        {
            for(int r=0;r<=4;r++)
            {
                int c=dp[i][l][r];
                if(c==-1) continue;
                //left
                if(l==0)
                {
                    if(dp[i+1][cur][r]==-1 || dp[i+1][cur][r]>c+2) dp[i+1][cur][r]=c+2;
                }
                else if(l==cur)
                {
                    if(dp[i+1][cur][r]==-1 || dp[i+1][cur][r]>c+1) dp[i+1][cur][r]=c+1;
                }
                else if(l==(cur+1)%4+1)
                {
                    if(dp[i+1][cur][r]==-1 || dp[i+1][cur][r]>c+4) dp[i+1][cur][r]=c+4;
                }
                else
                {
                    if(dp[i+1][cur][r]==-1 || dp[i+1][cur][r]>c+3) dp[i+1][cur][r]=c+3;
                }
                //right
                if(r==0)
                {
                    if(dp[i+1][l][cur]==-1 || dp[i+1][l][cur]>c+2) dp[i+1][l][cur]=c+2;
                }
                else if(r==cur)
                {
                    if(dp[i+1][l][cur]==-1 || dp[i+1][l][cur]>c+1) dp[i+1][l][cur]=c+1;
                }
                else if(r==(cur+1)%4+1)
                {
                    if(dp[i+1][l][cur]==-1 || dp[i+1][l][cur]>c+4) dp[i+1][l][cur]=c+4;
                }
                else
                {
                    if(dp[i+1][l][cur]==-1 || dp[i+1][l][cur]>c+3) dp[i+1][l][cur]=c+3;
                }
            }
        }
    }
    int res=1e9;
    for(int l=0;l<=4;l++)
    {
        for(int r=0;r<=4;r++)
        {
            if(dp[len][l][r]==-1) continue;
            if(dp[len][l][r]<res) res=dp[len][l][r];
        }
    }
    cout<<res;
}