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

using namespace std;

pair<pair<ll,ll>,ll> tree[LEN*4]; //assign, lazy

void update(int node, int l, int r, int left, int right, ll num)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        ll sumV=num*(r-l+1);
        tree[node]={{num,sumV},num};
        return;
    }
    int mid=(l+r)/2;
    ll lazy=tree[node].second;
    if(lazy!=-1)
    {
        tree[node*2]={{lazy,lazy*(mid-l+1)},lazy};
        tree[node*2+1]={{lazy,lazy*(r-mid)},lazy};
        tree[node].second=-1;
    }
    update(node*2,l,mid,left,right,num);
    update(node*2+1,mid+1,r,left,right,num);
    tree[node].first.second=tree[node*2].first.second+tree[node*2+1].first.second;
    return;
}

ll query(int node, int l, int r, int left, int right)
{
    if(right<l || r<left) return 0;
    else if(left<=l && r<=right) return tree[node].first.second;
    int mid=(l+r)/2;
    ll lazy=tree[node].second;
    if(lazy!=-1)
    {
        tree[node*2]={{lazy,lazy*(mid-l+1)},lazy};
        tree[node*2+1]={{lazy,lazy*(r-mid)},lazy};
        tree[node].second=-1;
    }
    return query(node*2,l,mid,left,right)+query(node*2+1,mid+1,r,left,right);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*4;i++) tree[i]={{0,0},-1};
    for(int i=0;i<m;i++)
    {
        int a,l,r;
        cin>>a>>l>>r;
        l++;
        if(a==1)
        {
            ll num;
            cin>>num;
            update(1,1,n,l,r,num);
        }
        else if(a==2)
        {
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
}