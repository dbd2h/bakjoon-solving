#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int s1Len=s1.size();
    int s2Len=s2.size();
    int dp[1001][1001];
    for(int i=0;i<=s1Len;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=s2Len;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=s1Len;i++)
    {
        for(int j=1;j<=s2Len;j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=dp[i-1][j-1];
            if(dp[i-1][j]>dp[i][j]) dp[i][j]=dp[i-1][j];
            if(dp[i][j-1]>dp[i][j]) dp[i][j]=dp[i][j-1];
        }
    }
    cout<<dp[s1Len][s2Len];
}