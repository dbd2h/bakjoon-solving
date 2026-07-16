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

struct Bit
{
    int c[41]={0};
};

Bit tree[LEN*4];
int arr[LEN]={0};
ll invTree[LEN*4];

Bit bitSum(Bit &a, Bit &b)
{
    Bit c;
    for(int i=0;i<41;i++)
    {
        c.c[i]=a.c[i]+b.c[i];
    }
    return c;
}

ll bitCmp(Bit &a, Bit &b)
{
    ll res=0;
    ll rightSum=0;
    for(int i=1;i<40;i++)
    {
        rightSum+=b.c[i];
        res+=a.c[i+1]*rightSum;
    }
    return res;
}

void update(int node, int l, int r, int idx, int num)
{
    if(l==r)
    {
        tree[node].c[arr[idx]]=0;
        tree[node].c[num]=1;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node]=bitSum(tree[node*2],tree[node*2+1]);
}

Bit query(int node, int l, int r, int left, int right)
{
    Bit c;
    int mid=(l+r)/2;
    if(right<l || r<left) return c;
    else if(left<=l && r<=right) return tree[node];
    Bit a=query(node*2,l,mid,left,right);
    Bit b=query(node*2+1,mid+1,r,left,right);
    return bitSum(a,b);
}

void invUpdate(int node, int l, int r, int n, int idx, int num)
{
    if(l==r)
    {
        invTree[node]=0;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) invUpdate(node*2,l,mid,n,idx,num);
    else invUpdate(node*2+1,mid+1,r,n,idx,num);
    invTree[node]=invTree[node*2]+invTree[node*2+1]+bitCmp(tree[node*2],tree[node*2+1]);
    return;
}

ll invQuery(int node, int l, int r, int n, int left, int right)
{
    int mid=(l+r)/2;
    if(right<l || r<left) return 0;
    else if(left<=l && r<=right) return invTree[node];
    Bit a,b;
    int lIdx=max(left,l);
    int rIdx=min(right,r);
    if(lIdx<=mid) a=query(1,1,n,lIdx,mid);
    if(mid+1<=rIdx) b=query(1,1,n,mid+1,rIdx);
    return invQuery(node*2,l,mid,n,left,right)+invQuery(node*2+1,mid+1,r,n,left,right)+bitCmp(a,b);
}

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(1,1,n,i,arr[i]);
        invUpdate(1,1,n,n,i,arr[i]);
    }
    for(int i=0;i<q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            ll res=invQuery(1,1,n,n,b,c);
            cout<<res<<"\n";
        }
        else if(a==2)
        {
            update(1,1,n,b,c);
            arr[b]=c;
            invUpdate(1,1,n,n,b,c);
        }
    }
}