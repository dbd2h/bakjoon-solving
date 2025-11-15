#include <iostream>
#include <algorithm>

#define LEN 56

typedef long long ll;

using namespace std;

int main()
{
    int n,R,G,B;
    cin>>n>>R>>G>>B;
    ll dp[11][LEN][LEN][LEN]={0};
    dp[0][0][0][0]=1;
    ll combi[101][101];
    for(int i=0;i<=100;i++)
    {
        combi[i][0]=1;
        combi[i][i]=1;
    }
    for(int i=2;i<=100;i++)
    {
        for(int j=1;j<i;j++)
        {
            combi[i][j]=combi[i-1][j-1]+combi[i-1][j];
        }
    }
    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        for(int r=0;r<=min(R,maxLen);r++)
        {
            for(int g=0;g<=min(G,maxLen);g++)
            {
                for(int b=0;b<=min(B,maxLen);b++)
                {
                    if(dp[i][r][g][b]==0) continue;
                    ll cur=dp[i][r][g][b];
                    int st=i+1;
                    if(r+st<=R)
                    {
                        dp[i+1][r+st][g][b]+=cur;
                    }
                    if(g+st<=G)
                    {
                        dp[i+1][r][g+st][b]+=cur;
                    }
                    if(b+st<=B)
                    {
                        dp[i+1][r][g][b+st]+=cur;
                    }
                    if((i+1)%2==0)
                    {
                        st=(i+1)/2;
                        if(r+st<=R && g+st<=G)
                        {
                            dp[i+1][r+st][g+st][b]+=cur*combi[i+1][st];
                        }
                        if(r+st<=R && b+st<=B)
                        {
                            dp[i+1][r+st][g][b+st]+=cur*combi[i+1][st];
                        }
                        if(g+st<=G && b+st<=B)
                        {
                            dp[i+1][r][g+st][b+st]+=cur*combi[i+1][st];
                        }
                    }
                    if((i+1)%3==0)
                    {
                        st=(i+1)/3;
                        if(r+st<=R && g+st<=G && b+st<=B)
                        {
                            dp[i+1][r+st][g+st][b+st]+=cur*combi[i+1][st]*combi[i+1-st][st];
                        }
                    }
                }
            }
        }
        maxLen+=(i+1);
    }
    ll res=0;
    for(int r=0;r<LEN;r++)
    {
        for(int g=0;g<LEN;g++)
        {
            for(int b=0;b<LEN;b++)
            {
                if(dp[n][r][g][b]==0) continue;
                res+=dp[n][r][g][b];
            }
        }
    }
    cout<<res;
}