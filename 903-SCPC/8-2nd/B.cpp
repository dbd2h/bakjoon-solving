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

using namespace std;

vector<int> v[LEN];
int arr[LEN];
int tree[LEN*4];

void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node]=1;
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
        tree[node]=0;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx);
    else update(node*2+1,mid+1,r,idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int left, int right)
{
    if(right<l || r<left) return 0;
    else if(left<=l && r<=right) return tree[node];
    int mid=(l+r)/2;
    return query(node*2,l,mid,left,right)+query(node*2+1,mid+1,r,left,right);
}

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) v[i].clear();
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        v[num].push_back(i);
        arr[i]=num;
    }
    build(1,1,n);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int cur=arr[i];
        int len=v[cur].size();
        if(len==0 || v[cur][len-1]<=i) continue;
        res+=query(1,1,n,i+1,v[cur][len-1]);
        update(1,1,n,i);
        update(1,1,n,v[cur][len-1]);
        v[cur].pop_back();
    }
    cout<<res<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}