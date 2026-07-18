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
#define LEN 2000001
#define INF (ll)(1e9+7)

using namespace std;

struct NODE
{
    ll max;
    ll min;
    ll res;
};

ll arr[LEN];
NODE tree[LEN*4];

void update(ll node, ll l, ll r, ll idx, ll num)
{
    if(l==r)
    {
        tree[node].max=num;
        tree[node].min=num;
        tree[node].res=0;
        return;
    }
    ll mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node].max=max(tree[node*2].max,tree[node*2+1].max);
    tree[node].min=min(tree[node*2].min,tree[node*2+1].min);
    tree[node].res=max(tree[node*2].res,tree[node*2+1].res);
    if(tree[node*2].min==0 || tree[node*2+1].min==0) return;
    if(tree[node*2].max>tree[node*2+1].min) tree[node].res=(r-l+1)/2;
}



void program()
{
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    ll len=1;
    while(len<n)
    {
        len*=2;
    }
    for(ll i=1;i<=len;i++)
    {
        if(i<=n) update(1,1,len,i,arr[i]);
        else update(1,1,len,i,INF);
    }
    cout<<tree[1].res<<"\n";
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