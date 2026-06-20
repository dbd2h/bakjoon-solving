#include <iostream>
#include <algorithm>

#define LEN 100001
typedef long long ll;

using namespace std;

int main()
{
    int n;
    cin>>n;
    ll dp[LEN];
    ll arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];

    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=abs(arr[i]-arr[i-1])+dp[i-1];
        if(i>2) dp[i]=min(dp[i],abs(arr[i]-arr[i-2])+dp[i-2]);
    }
    cout<<dp[n];
}

// 1. dp[i]: i번째 돌에 서 있을때까지의 최소 비용
// 2. 전이: dp[i] = min(dp[i-1] + (i-1)에서 i까지의 비용, dp[i-2] + (i-2)에서 i까지의 비용)
// 3. 초기값/답: dp[1]=0, 답은 dp[n]