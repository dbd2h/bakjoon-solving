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
    int n,w;
    cin>>n>>w;
    ll arr[101][2];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    } 
    ll dp[101][LEN];
    for(int i=0;i<=w;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j]=dp[i-1][j];
            int bef=j-arr[i][0];
            if(bef<0) continue;
            dp[i][j]=max(dp[i][j],dp[i-1][bef]+arr[i][1]);
        }
    }
    ll res=0;
    for(int i=0;i<=w;i++)
    {
        res=max(res,dp[n][i]);
    }
    cout<<res;
}

// 1. dp[i][j]: 1번째부터 i번째까지 물품들 중에서 골랐을 때 무게가 j인 경우의 최댓값
// 2. 전이: dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+arr[i]) (arr[i]: i번째 물건의 가치, w: i번째 물건의 무게, 단 j-w>=0 이여야 함)
// 3. 초기값/답: dp[0][0]=0 dp[0][j]=-∞ (1<=j<=W) dp[N][j]값 중 가장 큰 값