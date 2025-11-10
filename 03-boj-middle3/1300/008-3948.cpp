#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
    ll combi[21][21];
    for(int i=0;i<=20;i++)
    {
        combi[i][0]=1;
        combi[i][i]=1;
    }
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<i;j++)
        {
            combi[i][j]=combi[i-1][j-1]+combi[i-1][j];
        }
    }
    ll dp[21][2]={0};
    dp[0][0]=1;
    dp[0][1]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=20;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j%2==0)
            {
                dp[i][0]+=dp[j][0]*dp[i-j-1][1]*combi[i-1][j];
            }
            else if(j%2==1)
            {
                dp[i][1]+=dp[j][1]*dp[i-j-1][1]*combi[i-1][j];
            }
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<1<<"\n";
            continue;
        }
        cout<<dp[n][0]+dp[n][1]<<"\n";
    }
}