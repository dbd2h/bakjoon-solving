#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 1<<21
#define MOD (ll)(1e9+7)

using namespace std;

ll dp[LEN];
bool arr[21][21];

int orderF(int s)
{
    int res=0;
    while(s)
    {
        res+=(s%2);
        s/=2;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=1;i<(1<<n);i++)
    {
        dp[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    for(int s=0;s<(1<<n);s++)
    {
        int i=orderF(s);
        for(int j=0;j<n;j++)
        {
            if((s & (1<<j)) || !arr[i][j]) continue;
            dp[s | (1<<j)]+=dp[s];
            dp[s | (1<<j)]%=MOD;
        }
    }
    cout<<dp[(1<<n)-1];
}

// 1. dp[S]: S일때 매칭될 수 있는 경우의수. S는 0부터n-1까지의 여자들 중 매칭 된 여자 1, 매칭 안 된 여자를 0이라 하면 이를 이진수로 치환한 값. 
// 2. 전이: 남자 i번째 일 때 여자 j번째와 매칭한다면 S가 j번째가 0이고 1이 i개이며 길이가 n인 이진수라면 dp[S]값을 dp[S+(1<<j)]에 더해주기
// 3. 초기값/답: dp[0]=1, 답은 dp[2^n-1]