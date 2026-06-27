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
#define LEN 100001

using namespace std;

vector<int> graph[LEN];
bool check[LEN]={0};
ll dp[LEN][2];

void dfs(int cur)
{
    check[cur]=1;
    int count=0;
    for(auto& next : graph[cur])
    {
        if(check[next]) continue;
        count++;
        dfs(next);
        dp[cur][0]*=(dp[next][0]+dp[next][1]);
        dp[cur][0]%=MOD;
        dp[cur][1]*=dp[next][0];
        dp[cur][1]%=MOD;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=1;
    dfs(1);
    cout<<(dp[1][0]+dp[1][1])%MOD;
}

// 1. dp[i][0]: i번째 노드가 하얀색일 때 후손 노드들의 경우의 수, dp[i][1]: i버내 노드가 검은색일 때 후손 노드들의 경우의 수
// 2. 전이: dp[i][0] = i번째 노드의 자식 노드들의 흰색 검은색 dp(dp[j][0]+dp[j][1])의 곱. dp[i][1] = i번째 노드의 자식 노드의 흰색 dp(dp[j][0])의 곱
// 3. 초기값/답: 모든 노드 i의 dp[i][0]=dp[i][1]=1 답: 루트 노드 k의 dp[k][0]+dp[k][1]