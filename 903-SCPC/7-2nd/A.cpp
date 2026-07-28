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

using namespace std;

ll bs(ll l, ll r, ll num)
{
    if(l>r) return l-1;
    ll mid=(l+r)/2;
    if(mid*mid<num) return bs(mid+1,r,num);
    else return bs(l,mid-1,num);
}

void program()
{
    ll r;
    cin>>r;
    ll res=0;
    for(ll i=0;i<=r-1;i++)
    {
        ll cur=r*r-i*i;
        ll c=bs(0,r,cur);
        c=c*2+1;
        res+=c;
        if(i!=0) res+=c;
    }
    cout<<res<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}