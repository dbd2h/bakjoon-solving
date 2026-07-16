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

int tree[LEN*4]={0};
bool arr[LEN];

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
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update(int node, int l, int r, int idx)
{
    if(l==r)
    {
        arr[l]=!arr[l];
        tree[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx);
    else update(node*2+1,mid+1,r,idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int idx)
{
    int mid=(l+r)/2;
    if(l>idx) return 0;
    else if(r<=idx) return tree[node];
    else return query(node*2,l,mid,idx)+query(node*2+1,mid+1,r,idx);
}

int bs(int l, int r, int n, int num)
{
    int mid=(l+r)/2;
    int res=query(1,1,n,mid);
    if(num>res) return bs(mid+1,r,n,num);
    else if(num<res || !arr[mid]) return bs(l,mid-1,n,num);
    else return mid;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        b++;
        if(a==1)
        {
            update(1,1,n,b);
        }
        else
        {
            int res=bs(1,n,n,b);
            cout<<res-1<<"\n";
        }
    }
}