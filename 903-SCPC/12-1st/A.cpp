#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define INF (ll)2100000000000

using namespace std;

ll bs(ll l, ll r, ll n, ll m)
{
    if(l>r) return l;
    ll mid=(l+r)/2;
    ll res=n+mid/m-mid;
    if(res>0) return bs(mid+1,r,n,m);
    else return bs(l,mid-1,n,m);
}

void program()
{
    ll n,m;
    cin>>n>>m;
    ll res=bs(1,INF,n,m);
    cout<<res+1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<"\n";
        program();
    }
}