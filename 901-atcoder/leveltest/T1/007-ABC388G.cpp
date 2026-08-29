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
#define INF (int)(1e9+7)

using namespace std;

int arr[LEN];
int tree[LEN*4];

void build(int node, int l, int r, int n)
{
    if(l==r)
    {
        int idx=upper_bound(arr+1,arr+n+1,arr[l]/2)-arr-1;
        tree[node]=idx-l;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid,n);
    build(node*2+1,mid+1,r,n);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}

int query(int node, int l, int r, int left, int right)
{
    if(r<left || right<l) return INF;
    else if(left<=l && r<=right) return tree[node];
    int mid=(l+r)/2;
    int idx1=query(node*2,l,mid,left,right);
    int idx2=query(node*2+1,mid+1,r,left,right);
    return min(idx1,idx2);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n,n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int left,right;
        cin>>left>>right;
        int l=0;
        int r=(right-left+1)/2;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int idx=query(1,1,n,right-mid+1,right);
            if(idx+right-mid+1<left) r=mid-1;
            else l=mid+1;
        }
        cout<<l-1<<"\n";
    }
}