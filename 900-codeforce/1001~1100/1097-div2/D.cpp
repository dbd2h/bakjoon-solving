#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 2001

using namespace std;

ll modInverse(ll a, ll m)
{
    ll b=m-2;
    ll res=1;
    while(b)
    {
        if(b%2==1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}

void program()
{
    ll modV=998244353;
    int n;
    cin>>n;
    int a[LEN];
    int b[LEN];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    lld divB[LEN*LEN];
    int len=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            divB[len]=(lld)b[i]/(lld)b[j];
            len++;
            divB[len]=(lld)b[j]/(lld)b[i];
            len++;
        }
    }
    sort(divB,divB+len);
    ll res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            lld cur=(lld)a[j]/(lld)a[i];
            res+=(len-(upper_bound(divB,divB+len,cur)-divB));
            res%=modV;
        }
    }
    res=res*modInverse((ll)n*(ll)(n-1),modV)%modV;
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