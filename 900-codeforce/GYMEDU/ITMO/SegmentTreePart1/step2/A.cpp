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

struct Nod
{
    ll sum, lmax, rmax, max;
};

Nod tree[LEN*4];
ll arr[LEN];

void build(int node, int l, int r)
{
    if(l==r)
    {
        ll num=max(arr[l],0LL);
        Nod n={arr[l],num,num,num};
        tree[node]=n;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    Nod pn,n1,n2;
    n1=tree[node*2];
    n2=tree[node*2+1];
    pn.sum=n1.sum+n2.sum;
    pn.lmax=n1.sum+n2.lmax;
    pn.lmax=max(pn.lmax,n1.lmax);
    pn.rmax=n1.rmax+n2.sum;
    pn.rmax=max(pn.rmax,n2.rmax);
    pn.max=n1.rmax+n2.lmax;
    pn.max=max(pn.max,n1.max);
    pn.max=max(pn.max,n2.max);
    tree[node]=pn;
    return;
}
void update(int node, int l, int r, ll num, int idx)
{
    if(l==r)
    {
        ll maxV=max(num,0LL);
        Nod n={num,maxV,maxV,maxV};
        tree[node]=n;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,num,idx);
    else update(node*2+1,mid+1,r,num,idx);
    Nod pn,n1,n2;
    n1=tree[node*2];
    n2=tree[node*2+1];
    pn.sum=n1.sum+n2.sum;
    pn.lmax=n1.sum+n2.lmax;
    pn.lmax=max(pn.lmax,n1.lmax);
    pn.rmax=n1.rmax+n2.sum;
    pn.rmax=max(pn.rmax,n2.rmax);
    pn.max=n1.rmax+n2.lmax;
    pn.max=max(pn.max,n1.max);
    pn.max=max(pn.max,n2.max);
    tree[node]=pn;
    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    cout<<tree[1].max<<"\n";
    for(int i=0;i<m;i++)
    {
        int idx,num;
        cin>>idx>>num;
        idx++;
        update(1,1,n,num,idx);
        cout<<tree[1].max<<"\n";
    }
}