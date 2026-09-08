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
#define MOD 998244353

using namespace std;

ll dp[LEN]={0};
ll arr[LEN];

{
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll mul=1;
    ll bit=2;
    int idx=n-1;
    while(idx)
    {
        if(idx%2==1) mul*=bit;
        mul%=MOD;
        bit*=bit;
        bit%=MOD;
        idx/=2;
    }
    idx=MOD-2;
    ll inv=1;
    bit=2;
    while(idx)
    {
        if(idx%2==1) inv*=bit;
        inv%=MOD;
        bit*=bit;
        bit%=MOD;
        idx/=2;
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int cur=arr[i];
        if(cur>s) continue;
        else if(cur==s)
        {
            res+=mul;
            res%=MOD;
            continue;
        }
        if(dp[s-cur]!=0)
        {
            res+=(dp[s-cur]*inv%MOD);
            res%=MOD;
        }
        for(int j=s-cur-1;j>=0;j--)
        {
            dp[j+cur]+=(dp[j]*inv%MOD);
            dp[j+cur]%=MOD;
        }
        dp[cur]+=mul;
        dp[cur]%=MOD;
    }
    cout<<res;
}