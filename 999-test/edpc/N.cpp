#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 401

using namespace std;

int main()
{
    int n;
    cin>>n;
    ll sumArr[LEN];
    sumArr[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>sumArr[i];
        sumArr[i]+=sumArr[i-1];
    }
    ll dp[LEN][LEN];
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int i=1;i<n;i++)
    {
        for(int l=1;l<=n;l++)
        {
            int r=l+i;
            if(r>n) break;
            ll sumV=sumArr[r]-sumArr[l-1];
            for(int k=l;k<r;k++)
            {
                if(k==l)
                {
                    dp[l][r]=dp[l][k]+dp[k+1][r]+sumV;
                    continue;
                }
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+sumV);
            }
        }
    }
    cout<<dp[1][n];
}

// 1. dp[i][j]: i번째부터 j번째까지의 슬라임을 합치는데 드는 최소비용
// 2. 전이: dp[i][j] = dp[i][k] + dp[k+1][j] + i부터 j까지의 슬라임 사이즈 (i<=k<j)의 최솟값
// 3. 초깃값/답: dp[i][i]=0 (1<=i<=n), 답은 dp[1][n]