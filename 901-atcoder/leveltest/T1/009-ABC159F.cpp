#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 3001
#define MOD (ll)(998244353)

using namespace std;

ll dp[LEN]={0};
int arr[LEN];

int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int cur=arr[i];
        if(s-cur>0)
        {
            res+=dp[s-cur]*(n-i+1);
            res%=MOD;
        }  
        else if(s-cur==0)
        {
            res+=(ll)i*(n-i+1);
            res%=MOD;
        }
        for(int j=s-cur;j>=1;j--)
        {
            if(dp[j]==0) continue;
            dp[j+cur]+=dp[j];
            dp[j+cur]%=MOD;
        }
        dp[cur]+=i;
    }
    cout<<res;
}