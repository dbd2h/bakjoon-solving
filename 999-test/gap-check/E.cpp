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

using namespace std;

int cross[2][2]={{0,1},{-1,0}};

int main()
{
    int n;
    cin>>n;
    int arr[LEN][LEN];
    int dp[LEN][LEN]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        } 
    }
    dp[n-1][0]=arr[n-1][0];
    for(int x=n-1;x>=0;x--)
    {
        for(int y=0;y<n;y++)
        {
            for(int i=0;i<2;i++)
            {
                int xp=x+cross[i][0];
                int yp=y+cross[i][1];
                if(xp>=n || yp<0) continue;
                dp[xp][yp]=max(dp[xp][yp],dp[x][y]+arr[xp][yp]);
            }
        }
    }
    cout<<dp[0][n-1];
}