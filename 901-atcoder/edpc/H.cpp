#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 1001
#define MOD (ll)(1e9+7)

using namespace std;

int cross[2][2]={{1,0},{0,1}};

int main()
{
    int h,w;
    cin>>h>>w;
    bool arr[LEN][LEN];
    ll dp[LEN][LEN]={0};
    for(int i=0;i<h;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<w;j++)
        {
            if(s[j]=='.') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(arr[i][j]==0) continue;
            for(int k=0;k<2;k++)
            {
                int xp=i+cross[k][0];
                int yp=j+cross[k][1];
                if(xp>h || yp>w) continue;
                dp[xp][yp]+=dp[i][j];
                dp[xp][yp]%=MOD;
            }
        }
    }
    cout<<dp[h-1][w-1];
}

// 1. dp[i][j]: (1,1)에서 (i,j)로 갈 수 있는 경우의 수
// 2. 전이: dp[i][j]+=(dp[i-1][j]+dp[i][j-1]) 단 (i,j)가 #이면 X
// 3. 초기값/답: dp[1][1]=1, 답: dp[h][w]