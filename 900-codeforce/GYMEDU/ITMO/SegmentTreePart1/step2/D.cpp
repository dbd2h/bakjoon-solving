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

ll tree[LEN*4];
ll arr[LEN];

void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

void update(int node, int l, int r, int idx, ll num)
{
    if(l==r)
    {
        tree[node]=num;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int query(int node, int l, int r, int j, ll num)
{
    if(l==r)
    {
        if(l>=j && tree[node]>=num) return l;
        else return 0;
    }
    int mid=(l+r)/2;
    int res=0;
    if(tree[node*2]>=num && j<=mid) res=query(node*2,l,mid,j,num);
    if(res==0 && tree[node*2+1]>=num) res=query(node*2+1,mid+1,r,j,num);
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int b;
            ll c;
            cin>>b>>c;
            update(1,1,n,b+1,c);
        }
        else
        {
            ll b;
            int c;
            cin>>b>>c;
            cout<<query(1,1,n,c+1,b)-1<<"\n";
        }
    }
}