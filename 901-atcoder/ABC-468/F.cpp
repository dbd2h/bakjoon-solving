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
#define LEN 500001
#define INF (-1e9)

using namespace std;

int tree[LEN*4];
int arr[LEN];

void update(int node, int l, int r, int idx, int num)
{
    if(l==r)
    {
        tree[node]=max(tree[node],num);
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int query(int node, int l, int r, int idx)
{
    if(l>idx) return INF;
    else if(r<=idx) return tree[node];
    int mid=(l+r)/2;
    return max(query(node*2,l,mid,idx),query(node*2+1,mid+1,r,idx));
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<LEN*4;i++) tree[i]=INF;
    update(1,0,n,0,0);
    int addV=0;
    int M=0;
    for(int i=1;i<=n;i++)
    {
        int cur=arr[i];
        int num=query(1,0,n,cur);
        if(cur>M)
        {
            update(1,0,n,M,num);
            addV++;
            M=cur;
        }
        else if(num!=INF)
        {
            update(1,0,n,cur,num+1);
        }
    }
    cout<<query(1,0,n,n)+addV;
}