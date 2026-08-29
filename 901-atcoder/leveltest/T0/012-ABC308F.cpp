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

using namespace std;

int tree[LEN*4];
int arr[LEN];
int coupon[LEN][2];
vector<pair<int,int>> v;

void update(int node, int l, int r, int idx, int num)
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

int query(int node, int l, int r, int num)
{
    if(tree[node]<num) return -1;
    if(l==r)
    {
        return l;
    }
    int mid=(l+r)/2;
    if(tree[node*2]>=num) return query(node*2,l,mid,num);
    else return query(node*2+1,mid+1,r,num);
}

int cmp1(int n1, int n2)
{
    return n1<n2;
}

int cmp2(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second>p2.second;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=m;i++) cin>>coupon[i][0];
    for(int i=1;i<=m;i++) cin>>coupon[i][1];
    for(int i=1;i<=m;i++) v.push_back({coupon[i][0],coupon[i][1]});
    sort(arr+1,arr+n+1,cmp1);
    sort(v.begin(),v.end(),cmp2);
    for(int i=1;i<=n;i++)
    {
        update(1,1,n,i,arr[i]);
    }
    for(auto&p : v)
    {
        int l=p.first;
        int d=p.second;
        int idx=query(1,1,n,l);
        if(idx==-1) continue;
        arr[idx]-=d;
        update(1,1,n,idx,0);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res+=arr[i];
    }
    cout<<res;
}