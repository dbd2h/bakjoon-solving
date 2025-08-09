#include <iostream>
#include <memory.h>


using namespace std;



int main()
{
    long long MOD=1000000007;
    long long dp[52][52][52][52]={0};
    dp[0][0][0][0]=1;
    int S,A,B,C;
    cin>>S>>A>>B>>C;
    for(int s=0;s<=S;s++)
    {
        for(int a=0;a<=A;a++)
        {
            if(a>s) break;
            for(int b=0;b<=B;b++)
            {
                if(b>s) break;
                for(int c=0;c<=C;c++)
                {
                    if(c>s) break;
                    dp[s+1][a+1][b][c]+=dp[s][a][b][c];
                    dp[s+1][a+1][b][c]%=MOD;
                    dp[s+1][a][b+1][c]+=dp[s][a][b][c];
                    dp[s+1][a][b+1][c]%=MOD;
                    dp[s+1][a][b][c+1]+=dp[s][a][b][c];
                    dp[s+1][a][b][c+1]%=MOD;
                    dp[s+1][a+1][b+1][c]+=dp[s][a][b][c];
                    dp[s+1][a+1][b+1][c]%=MOD;
                    dp[s+1][a+1][b][c+1]+=dp[s][a][b][c];
                    dp[s+1][a+1][b][c+1]%=MOD;
                    dp[s+1][a][b+1][c+1]+=dp[s][a][b][c];
                    dp[s+1][a][b+1][c+1]%=MOD;
                    dp[s+1][a+1][b+1][c+1]+=dp[s][a][b][c];
                    dp[s+1][a+1][b+1][c+1]%=MOD;
                }
            }
        }
    }
    cout<<dp[S][A][B][C];
}