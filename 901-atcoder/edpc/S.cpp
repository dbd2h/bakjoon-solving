#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define MOD (ll)(1e9+7)

using namespace std;

int main()
{
    ll dp[10001][2][100]={0};
    string k;
    int d;
    cin>>k>>d;
    int len=k.size();
    dp[0][1][0]=1;
    for(int i=0;i<len;i++)
    {
        int cur=k[i]-'0';
        for(int j=0;j<d;j++)
        {
            if(dp[i][0][j]==0 && dp[i][1][j]==0) continue;
            for(int digit=0;digit<=9;digit++)
            {
                if(digit<cur)
                {
                    dp[i+1][0][(j+digit)%d]+=dp[i][1][j];
                }
                else if(digit==cur)
                {
                    dp[i+1][1][(j+digit)%d]+=dp[i][1][j];
                    dp[i+1][1][(j+digit)%d]%=MOD;
                }
                dp[i+1][0][(j+digit)%d]+=dp[i][0][j];
                dp[i+1][0][(j+digit)%d]%=MOD;
            }
        }
    }
    cout<<(dp[len][0][0]+dp[len][1][0]-1+MOD)%MOD;
}
