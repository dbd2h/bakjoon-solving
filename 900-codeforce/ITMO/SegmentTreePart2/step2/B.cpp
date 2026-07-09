#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 100001
#define MOD (ll)(1e9+7)

using namespace std;

pair<ll,ll> tree[LEN*4]; //mul, sum

void update(int node, int l, int r, int left, int right, ll mul)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        tree[node].first*=mul;
        tree[node].first%=MOD;
        tree[node].second*=mul;
        tree[node].second%=MOD;
        return;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,left,right,mul);
    update(node*2+1,mid+1,r,left,right,mul);
    tree[node].second=(tree[node*2].second+tree[node*2+1].second)%MOD*tree[node].first%MOD;
}

ll query(int node, int l, int r, int left, int right)
{
    if(right<l || r<left) return 0;
    else if(left<=l && r<=right) return tree[node].second;
    int mid=(l+r)/2;
    ll res=(query(node*2,l,mid,left,right)+query(node*2+1,mid+1,r,left,right))%MOD;
    return res*tree[node].first%MOD;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*4;i++) tree[i]={1,1};
    for(int i=1;i<=n;i++) update(1,1,n,i,i,1);
    for(int i=0;i<m;i++)
    {
        int a,l,r;
        cin>>a>>l>>r;
        l++;
        if(a==1)
        {
            ll mul;
            cin>>mul;
            update(1,1,n,l,r,mul);
        }
        else if(a==2)
        {
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
}