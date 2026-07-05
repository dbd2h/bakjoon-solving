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
ll tree[LEN*4]={0};
ll arr[LEN];
ll resArr[LEN]={0};
bool check[LEN]={0};

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
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int idx)
{
    int mid=(l+r)/2;
    if(idx<l) return 0;
    else if(r<=idx) return tree[node];
    else return query(node*2,l,mid,idx)+query(node*2+1,mid+1,r,idx);
}

int bs(int l, int r, int n, int num)
{
    int mid=(l+r)/2;
    int res=n-mid-(query(1,1,n,n)-query(1,1,n,mid));
    if(res>num) return bs(mid+1,r,n,num);
    else if(res<num || check[mid]) return bs(l,mid-1,n,num);
    else return mid;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=n;i>=1;i--)
    {
        int num=bs(1,n,n,arr[i]);
        update(1,1,n,num,1);
        resArr[i]=num;
        check[num]=1;
    }
    for(int i=1;i<=n;i++) cout<<resArr[i]<<" ";
}