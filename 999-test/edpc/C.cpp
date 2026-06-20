#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 100001

using namespace std;

int main()
{
    int n;
    cin>>n;
    ll arr[LEN][3];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++) cin>>arr[i][j];
    }
    ll dp[LEN][3];
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            dp[i][j]=arr[i][j];
            dp[i][j]+=max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
        }
    }
    ll res=0;
    for(int i=0;i<3;i++) res=max(res,dp[n][i]);
    cout<<res;
}

// 1. dp[i][j]: i일에 j활동을 했을 당시에 최댓값 (1<=i<=n, 0<=j<=2) 
// 2. 전이: dp[i][j]=arr[i][j] + k!=j 인 dp[i-1][k] 중 최대
// 3. 초기값/답: dp[0][j]=0, dp[n][j] (0<=j<=2) 중 가장 큰 값이 답