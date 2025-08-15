#include <iostream>

using namespace std;

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    long long MOD=1'000'001;
    long long dp[102][102][102]={0};
    dp[0][0][0]=1;
    for(long long i=0;i<n;i++) // col
    {
        for(long long j=0;j<=k;j++) // rook count
        {
            for(long long a=0;a<=m;a++) // can't place
            {
                // no place
                dp[i+1][j][a]+=dp[i][j][a]; 
                dp[i+1][j][a]%=MOD;
                // place 1
                if(j+1>k) continue;
                if(a+1>m) continue;
                dp[i+1][j+1][a+1]+=(dp[i][j][a]*(m-a));
                dp[i+1][j+1][a+1]%=MOD;
                // place row 2
                if(j+2>k) continue;
                if(a+2<=m) dp[i+1][j+2][a+2]+=(dp[i][j][a]*(m-a)*(m-a-1)/2);
                dp[i+1][j+2][a+2]%=MOD;
                // place col 2
                if(i+2>n) continue;
                dp[i+2][j+2][a+1]+=(dp[i][j][a]*(m-a)*(n-i-1));
                dp[i+2][j+2][a+1]%=MOD;
            }
        }
    }
    long long result=0;
    for(long long i=0;i<=m;i++)
    {
        result+=dp[n][k][i];
        result%=MOD;
    }
    cout<<result;
}