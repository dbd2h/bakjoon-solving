#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 101

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[LEN][LEN];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>arr[i][j];
    }
    int dp[LEN][LEN][2];
    for(int i=1;i<=n;i++)
    {
        int a=0;
        int b=0;
        for(int j=1;j<=k;j++)
        {
            if(arr[j][i]==1) a++;
            else b++;
        }
        dp[1][i][0]=a;
        dp[1][i][1]=b;
    }
    for(int i=2;i<=n-k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a=dp[i][j][0];
            int b=dp[i][j][1];
            if(arr[i-1][j]==1) a--;
            else b--;
            if(arr[i+k-1][j]==1) a++;
            else b++;
            dp[i][j][0]=a;
            dp[i][j][1]=b;
        }
    }
    int res=0;
    for(int i=1;i<=n-k;i++)
    {
        int a=0;
        int b=0;
        for(int j=1;j<=k;j++)
        {
            a+=dp[i][j][0];
            b+=dp[i][j][1];
        }
        res=max(res,abs(a-b));
        for(int j=2;j<=n-k;j++)
        {
            a-=dp[i][j-1][0];
            b-=dp[i][j-1][1];
            a+=dp[i][j+k-1][0];
            b+=dp[i][j+k-1][1];
            res=max(res,abs(a-b));
        }
    }
    cout<<res;
}