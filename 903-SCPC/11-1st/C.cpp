#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    ll MOD=1'000'000'007;
    string s;
    cin>>s;
    int len=s.size();
    ll dp[100002][2][3];
    dp[0][0][0]=dp[0][0][1]=dp[0][0][2]=dp[0][1][0]=dp[0][1][1]=dp[0][1][2]=0;
    dp[0][1][0]=1;
    for(int i=0;i<len;i++)
    {
        int cur=s[i]-'0';
        for(int j=0;j<3;j++)
        {
            dp[i+1][0][j]=dp[i+1][1][j]=0;
            dp[i+1][0][j]+=(dp[i][0][0]+dp[i][0][1]+dp[i][0][2]);
            dp[i+1][0][j]%=MOD;
            if(cur>j)
            {
                dp[i+1][0][j]+=(dp[i][1][0]+dp[i][1][1]+dp[i][1][2]);
                dp[i+1][0][j]%=MOD;
            }
            else if(cur==j)
            {
                dp[i+1][1][j]+=(dp[i][1][0]+dp[i][1][1]+dp[i][1][2]);
                dp[i+1][1][j]%=MOD;
            }
        }
    }
    cout<<(dp[len][0][0]+dp[len][0][1]+dp[len][0][2]+dp[len][1][0]+dp[len][1][1]+dp[len][1][2]-1+MOD)%MOD<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<"\n";
        program();
    }
}