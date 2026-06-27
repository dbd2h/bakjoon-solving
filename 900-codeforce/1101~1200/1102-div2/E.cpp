#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 500001
#define MOD (ll)(1e9+7)

using namespace std;

ll revArr[LEN];
ll factoArr[LEN];
ll revPrefixArr[LEN];
ll arr[LEN];

ll res=1;

pair<ll,ll> gcd(ll a, ll b)
{
    if(a%b==1)
    {
        return {1,-a/b};
    }
    pair<ll,ll> p=gcd(b,a%b);
    return {p.second,-a/b*p.second+p.first};
}

bool resF(int l, int r)
{
    if(l>r) return true;
    for(int i=0;i<=r-l;i++)
    {
        ll idx1=i+l;
        ll idx2=r-i;
        ll mul=(idx1-l+1)*(r-idx1+1);
        if(arr[idx1]==mul)
        {
            res*=factoArr[r-l];
            res%=MOD;
            res*=revPrefixArr[i];
            res%=MOD;
            res*=revPrefixArr[r-l-i];
            res%=MOD;
            if(!resF(l,idx1-1)) return false;
            if(!resF(idx1+1,r)) return false;
            return true;
        }
        if(arr[idx2]==mul)
        {
            res*=factoArr[r-l];
            res%=MOD;
            res*=revPrefixArr[i];
            res%=MOD;
            res*=revPrefixArr[r-l-i];
            res%=MOD;
            if(!resF(l,idx2-1)) return false;
            if(!resF(idx2+1,r)) return false;
            return true;
        }
    }
    return false;
}

void program()
{
    res=1;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(!resF(1,n)) cout<<0<<"\n";
    else cout<<res<<"\n";
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    revArr[1]=1;
    for(int i=2;i<LEN;i++)
    {
        pair<ll,ll> p=gcd(MOD,i);
        ll rev=p.second+MOD;
        rev%=MOD;
        revArr[i]=rev;
    }
    factoArr[0]=factoArr[1]=1;
    revPrefixArr[0]=revPrefixArr[1]=1;
    for(ll i=2;i<LEN;i++)
    {
        factoArr[i]=(factoArr[i-1]*i)%MOD;
        revPrefixArr[i]=(revPrefixArr[i-1]*revArr[i])%MOD;
    }
    for(int i=0;i<t;i++)
    {
        program();
    }
}