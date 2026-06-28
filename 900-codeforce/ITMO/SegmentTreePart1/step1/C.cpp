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
#define INF (ll)1e18

using namespace std;

ll tree[LEN*4][2];
ll arr[LEN];

pair<ll,int> checkMin(int idx1, int idx2)
{
    pair<ll,int> p;
    if(tree[idx1][0]>tree[idx2][0]) p={tree[idx2][0],tree[idx2][1]};
    else if(tree[idx1][0]<tree[idx2][0]) p={tree[idx1][0],tree[idx1][1]};
    else if(tree[idx1][0]==tree[idx2][0]) p={tree[idx1][0],tree[idx1][1]+tree[idx2][1]};
    return p;
}

void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node][0]=arr[l];
        tree[node][1]=1;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    pair<ll,int> p;
    p=checkMin(node*2,node*2+1);
    tree[node][0]=p.first;
    tree[node][1]=p.second;
}

void update(int node, int l, int r, int idx, ll num)
{
    if(l==r)
    {
        tree[node][0]=num;
        tree[node][1]=1;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    pair<ll,int> p;
    p=checkMin(node*2,node*2+1);
    tree[node][0]=p.first;
    tree[node][1]=p.second;
}

pair<ll,int> query(int node, int l, int r, int start, int end)
{
    if(end<l || r<start) return {INF,0};
    else if(start<=l && r<=end) return {tree[node][0], tree[node][1]};
    int mid=(l+r)/2;
    pair<ll,int> p1,p2;
    p1=query(node*2,l,mid,start,end);
    p2=query(node*2+1,mid+1,r,start,end);
    if(p1.first>p2.first) return p2;
    else if(p1.first<p2.first) return p1;
    else return {p1.first,p1.second+p2.second};
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
        ll c;
        cin>>a>>b>>c;
        b++;
        if(a==1)
        {
            update(1,1,n,b,c);
        }
        else if(a==2)
        {
            pair<ll,int> p=query(1,1,n,b,c);
            cout<<p.first<<" "<<p.second<<"\n";
        }
    }
}