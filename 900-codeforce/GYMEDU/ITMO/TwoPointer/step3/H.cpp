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
#define LEN 100001

using namespace std;

int cmp(ll n1, ll n2)
{
    return n1>n2;
}

int main()
{
    ll n,m,s,A,B;
    cin>>n>>m>>s>>A>>B;
    ll aArr[LEN],bArr[LEN];
    for(ll i=0;i<n;i++) cin>>aArr[i];
    for(ll i=0;i<m;i++) cin>>bArr[i];
    sort(aArr,aArr+n,cmp);
    sort(bArr,bArr+m,cmp);
    ll w=0;
    ll aIdx=-1;
    ll bIdx=-1;
    ll c=0;
    while(aIdx<n)
    {
        if(w+A<=s)
        {
            aIdx++;
            w+=A;
            c+=aArr[aIdx];
        }
        else break;
        if(aIdx==n-1) break;
    }
    ll res=c;
    while(bIdx<m && aIdx>=-1)
    {
        while(bIdx<m)
        {
            if(w+B<=s)
            {
                bIdx++;
                if(bIdx==m) break;
                w+=B;
                c+=bArr[bIdx];
            }
            else break;
        }
        res=max(res,c);
        if(aIdx==-1) break;
        w-=A;
        c-=aArr[aIdx];
        aIdx--;
    }
    cout<<res;
}