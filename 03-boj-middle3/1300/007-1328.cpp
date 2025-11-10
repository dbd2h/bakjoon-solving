#include <iostream>

#define LEN 101
typedef long long ll;

using namespace std;

int main()
{
    ll dp[LEN][LEN][LEN]={0};
    dp[1][1][1]=1;
    ll MOD=1'000'000'007;
    for(int i=1;i<LEN-1;i++)
    {
        for(int l=1;l<=i;l++)
        {
            for(int r=1;r<=i;r++)
            {
                dp[i+1][l+1][r]+=dp[i][l][r];
                dp[i+1][l+1][r]%=MOD;
                dp[i+1][l][r+1]+=dp[i][l][r];
                dp[i+1][l][r+1]%=MOD;
                dp[i+1][l][r]+=dp[i][l][r]*(i-1);
                dp[i+1][l][r]%=MOD;
            }
        }
    }
    int N,L,R;
    cin>>N>>L>>R;
    cout<<dp[N][L][R];
}