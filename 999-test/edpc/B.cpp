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
    int n,k;
    cin>>n>>k;
    ll arr[LEN];
    ll dp[LEN];
    dp[1]=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=2;i<=n;i++)
    {
        ll h=1e9;
        for(int j=1;j<=k;j++)
        {
            int bef=i-j;
            if(bef<=0) break;
            ll cur=dp[bef]+abs(arr[i]-arr[bef]);
            h=min(h,cur);
        }
        dp[i]=h;
    }
    cout<<dp[n];
}

// 1. dp[i]: i번째 돌에 도착하는 최소 비용
// 2. 전이: dp[i]=min(dp[i-1]+|hi-h(i-1)|, ... , dp[i-k]+|hi-h(i-k)|)
// 3. 초기값/답: dp[i]=0, dp[n]이 답