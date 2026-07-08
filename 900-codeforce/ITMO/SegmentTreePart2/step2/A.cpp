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

pair<ll,ll> tree[LEN*4]; // min, add

void update(int node, int l, int r, int left, int right, ll num)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        tree[node].first+=num;
        tree[node].second+=num;
        return;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,left,right,num);
    update(node*2+1,mid+1,r,left,right,num);
    ll minV=min(tree[node*2].first, tree[node*2+1].first);
    tree[node].first=minV+tree[node].second;
}

ll query(int node, int l, int r, int left, int right)
{
    if(right<l || r<left) return (ll)(1e15);
    else if(left<=l && r<=right) return tree[node].first;
    int mid=(l+r)/2;
    ll minV=min(query(node*2,l,mid,left,right), query(node*2+1,mid+1,r,left,right));
    return minV+tree[node].second;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*4;i++) tree[i]={0,0};
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        b++;
        if(a==1)
        {
            ll num;
            cin>>num;
            update(1,1,n,b,c,num);
        }
        else if(a==2)
        {
            cout<<query(1,1,n,b,c)<<"\n";
        }
    }
}