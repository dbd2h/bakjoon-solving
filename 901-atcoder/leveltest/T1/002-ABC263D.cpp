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
#define LEN 200001

using namespace std;

ll arr[LEN];
ll dp[LEN];

int main()
{
    ll n,l,r;
    cin>>n>>l>>r;
    ll totV=0;
    ll totL=0;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        totV+=arr[i];
        totL+=l;
        dp[i]=min(dp[i-1],totL-totV);
    }
    ll res=totV+dp[n];
    ll totR=0;
    
    for(int i=n;i>=1;i--)
    {
        totR+=(r-arr[i]);
        ll cur=totV+totR+dp[i-1];
        res=min(res,cur);
    }
    cout<<res;
}