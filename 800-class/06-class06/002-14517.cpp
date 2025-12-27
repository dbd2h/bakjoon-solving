#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int MOD=10'007;
    int dp[1000][1000]={0};
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        int sumV=0;
        for(int j=i;j>=0;j--)
        {
            if(i==j)
            {
                dp[j][i]=1;
                sumV++;
                continue;
            }
            int l=s[j]-'a';
            int r=s[i]-'a';
            if(l!=r) continue;
            dp[j][i]=1;
            if(j+1<=i-1) dp[j][i]+=dp[j+1][i-1];
            dp[j][i]%=MOD;
            sumV+=dp[j][i];
            sumV%=MOD;
        }
        for(int j=0;j<i;j++)
        {
            int cur=dp[j][i];
            dp[j][i]=dp[j][i-1]+sumV;
            dp[j][i]%=MOD;
            sumV-=cur;
            sumV+=MOD;
            sumV%=MOD;
        }
    }
    cout<<dp[0][len-1];
}