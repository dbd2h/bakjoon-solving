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
#define LEN 200001
#define INF (int)(1e9)

using namespace std;

struct NODE
{
    int max;
    int min;
};

int arr[LEN];
NODE tree[LEN*4];

void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node].max=arr[l];
        tree[node].min=arr[r];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node].max=max(tree[node*2].max,tree[node*2+1].max);
    tree[node].min=min(tree[node*2].min,tree[node*2+1].min);
}

NODE query(int node, int l, int r, int left, int right)
{
    if(right<l || r<left) return {0,INF};
    else if(left<=l && r<=right) return tree[node];
    int mid=(l+r)/2;
    NODE n1=query(node*2,l,mid,left,right);
    NODE n2=query(node*2+1,mid+1,r,left,right);
    return {max(n1.max,n2.max),min(n1.min,n2.min)};
}

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int l=i;
        int r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            NODE cur=query(1,1,n,i,mid);
            if(cur.max>x || cur.min<y) r=mid-1;
            else l=mid+1;
        }
        int right=l-1;
        l=i;
        r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            NODE cur=query(1,1,n,i,mid);
            if(cur.max<x || cur.min>y) l=mid+1;
            else r=mid-1;
        }
        int left=r+1;
        if(left<=right) res+=(right-left+1);
    }
    cout<<res;
}