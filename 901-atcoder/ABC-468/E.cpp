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
#define MOD (ll)998244353
#define LEN 500001

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int l=1;
    int r=n;
    ll res=0;
    ll minus=0;
    ll m=0; 
    ll tot=0;
    for(int i=1;i<=n;i++)
    {
        tot+=arr[i];
        tot%=MOD;
    }
    while(l<=r)
    {
        ll idx=MOD-2;
        ll inv=1;
        ll mul=l;
        while(idx)
        {
            if(idx%2==1)
            {
                inv*=mul;
                inv%=MOD;
            }
            mul*=mul;
            mul%=MOD;
            idx/=2;
        }
        ll cur=tot*l;
        cur%=MOD;
        cur-=minus;
        cur%=MOD;
        cur=(cur+MOD)%MOD;
        cur*=inv;
        cur%=MOD;
        res+=cur;
        res%=MOD;

        if(l==r) break;

        idx=MOD-2;
        inv=1;
        mul=r;
        while(idx)
        {
            if(idx%2==1)
            {
                inv*=mul;
                inv%=MOD;
            }
            mul*=mul;
            mul%=MOD;
            idx/=2;
        }
        cur=tot*l;
        cur%=MOD;
        cur-=minus;
        cur%=MOD;
        cur=(cur+MOD)%MOD;
        cur*=inv;
        cur%=MOD;
        res+=cur;
        res%=MOD;
        m+=(arr[l]+arr[r]);
        m%=MOD;
        minus+=m;
        minus%=MOD;
        minus+=MOD;
        minus%=MOD;
        l++;
        r--;
        
    }
    cout<<res;
}