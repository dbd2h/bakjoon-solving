#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    string s, devil, angel;
    cin>>s>>devil>>angel;
    int len=s.size();
    int len2=devil.size();
    ll dp[20][100][2]={0};
    char cur=s[0];
    for(int i=0;i<len2;i++)
    {
        char dCur=devil[i];
        char aCur=angel[i];
        if(cur==dCur) dp[0][i][0]=1;
        if(cur==aCur) dp[0][i][1]=1;
    }
    for(int i=1;i<len;i++)
    {
        cur=s[i];
        for(int j=0;j<len2;j++)
        {
            if(dp[i-1][j][0]==0) continue;
            
            for(int k=j+1;k<len2;k++)
            {
                if(cur==angel[k]) dp[i][k][1]+=dp[i-1][j][0];
            }
        }
        for(int j=0;j<len2;j++)
        {
            if(dp[i-1][j][1]==0) continue;
            
            for(int k=j+1;k<len2;k++)
            {
                if(cur==devil[k]) dp[i][k][0]+=dp[i-1][j][1];
            }
        }
    }
    ll res=0;
    for(int i=0;i<len2;i++)
    {
        res+=dp[len-1][i][0];
        res+=dp[len-1][i][1];
    }
    cout<<res;
}