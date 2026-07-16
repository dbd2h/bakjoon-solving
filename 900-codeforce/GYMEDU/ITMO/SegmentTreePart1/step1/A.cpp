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
    tree[node]=(tree[node*2]+tree[node*2+1]);
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
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node, int l, int r, int start, int end)
{
    if(end<l || r<start) return 0;
    else if(start<=l && r<=end) return tree[node];
    int mid=(l+r)/2;
    return query(node*2,l,mid,start,end)+query(node*2+1,mid+1,r,start,end);
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
            cout<<query(1,1,n,b,c)<<"\n";
        }
    }
}

// 1. 노드가 담는 값: 이 노드가 담는 구간의 합
// 2. merge: 자식노드 값의 합
// 3. 갱신이 트리를 어떻게 타고 오르내리나: 잎까지 내려가서 각각 arr값들로 바꾸고 merge하며 올라옴