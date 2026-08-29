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
#define LEN 300001
#define MOD (ll)(998244353)

using namespace std;

int arr[LEN];
ll dp[LEN];
int tree[LEN*4];

void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node]=0;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=0;
}

void update(int node, int l, int r, int idx)
{
    if(l==r)
    {
        tree[node]=1;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx);
    else update(node*2+1,mid+1,r,idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int idx)
{
    if(r<=idx) return tree[node];
    else if(idx<l) return 0;
    int mid=(l+r)/2;
    return query(node*2,l,mid,idx)+query(node*2+1,mid+1,r,idx);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    dp[n]=0;
    update(1,1,n,arr[n]);
    ll sumV=0;
    for(int i=n-1;i>=1;i--)
    {
        dp[i]=sumV;
        int cur=arr[i];
        int c=query(1,1,n,cur-1);
        dp[i]+=c;
        dp[i]%=MOD;
        sumV+=dp[i];
        sumV%=MOD;
        update(1,1,n,cur);
    }
    build(1,1,n);
    update(1,1,n,arr[1]);
    ll res=0;
    for(int i=2;i<=n;i++)
    {
        int cur=arr[i];
        int c=query(1,1,n,cur-1);
        res+=dp[i]*c;
        res%=MOD;
        update(1,1,n,cur);
    }
    cout<<res;
}