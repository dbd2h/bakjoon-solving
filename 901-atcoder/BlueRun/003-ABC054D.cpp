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
#define INF (int)(1e9)

using namespace std;

int main()
{
    int n,ma,mb;
    cin>>n>>ma>>mb;
    int dp[LEN][LEN];
    for(int i=1;i<=n*10;i++)
    {
        for(int j=1;j<=n*10;j++) dp[i][j]=INF;
    }
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int x=i*10;x>=1;x--)
        {
            for(int y=i*10;y>=1;y--)
            {
                if(dp[x][y]==INF) continue;
                int xp=x+a;
                int yp=y+b;
                dp[xp][yp]=min(dp[xp][yp],c+dp[x][y]);
            }
        }
        dp[a][b]=min(dp[a][b],c);
    }
    int res=INF;
    int x=ma;
    int y=mb;
    while(x<=n*10 && y<=n*10)
    {
        res=min(res,dp[x][y]);
        x+=ma;
        y+=mb;
    }
    if(res==INF) cout<<-1;
    else cout<<res;
}   

// time: 21M 43S Solve
// 1. 신호: 우선 숫자의 크기가 작음. A와 B의 최대의 경우가 각각 400임. 그리고 1을 하냐마냐, 2를 하냐마냐 이런식.
// 2. 도구: 위의 단서들을 근거로 dp임을 추정.
// 3. 막힌 지점: 풀이를 못 떠올린건 아니고, 다만 WA가 뜬 것에 대해 얘기하면 dp를 업데이트 할 때 1부터 해버리면 dp를 이전값에서 한 게
// 같은 for문에서 또 만날 수 있다. 즉 (3,2)를 사서 dp[3][2]를 업데이트 했는데, 이를 같은 for문에서 또 만나 dp[6][4], dp[9][6] 이렇게 됨. 즉 큰값부터 작은값으로 탐색해야 함.