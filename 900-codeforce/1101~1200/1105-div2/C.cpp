#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 1000001
#define MOD (ll)998244353
 

using namespace std;

ll prefixArr[LEN];
ll suffixArr[LEN];

ll xorF(ll n1, ll n2)
{
    ll res=0;
    ll powN=1;
    while(n1 || n2)
    {
        if(n1%2 != n2%2) res+=powN;
        powN*=2;
        n1/=2;
        n2/=2;
    }
    return res;
}

void program()
{
    
    int n;
    cin>>n;
    ll arr[LEN];
    ll res=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    prefixArr[1]=arr[1];
    suffixArr[n]=arr[n];
    if(n==1)
    {
        cout<<0<<"\n";
        return;
    }
    for(int i=2;i<=n;i++)
    {
        int r=n-i+1;
        prefixArr[i]=xorF(prefixArr[i-1],arr[i]);
        suffixArr[r]=xorF(suffixArr[r+1],arr[r]);
    }
    for(int i=1;i<=n;i++)
    {
        ll cur=0;
        if(i!=1) cur=xorF(cur,prefixArr[i-1]);
        if(i!=n) cur=xorF(cur,suffixArr[i+1]);
        if(cur<=arr[i]) res++;
        if(cur==arr[i]) break;
    }
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}