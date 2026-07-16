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
    int bit[41]={0};
};

Bit tree[LEN*4];
int arr[LEN];

Bit bitSum(Bit &a, Bit &b)
{
    Bit c;
    for(int i=1;i<=40;i++) c.bit[i]=a.bit[i]+b.bit[i];
    return c;
}

void update(int node, int l, int r, int idx, int num)
{
    if(l==r)
    {
        tree[node].bit[arr[idx]]=0;
        tree[node].bit[num]=1;
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
    if(right<l || r<left) return c;
    else if(left<=l && r<=right) return tree[node];
    int mid=(l+r)/2;
    Bit a,b;
    a=query(node*2,l,mid,left,right);
    b=query(node*2+1,mid+1,r,left,right);
    c=bitSum(a,b);
    return c;
}

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(1,1,n,i,arr[i]);
    }
    for(int i=0;i<q;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            Bit resBit=query(1,1,n,b,c);
            int res=0;
            for(int i=1;i<=40;i++)
            {
                if(resBit.bit[i]==0) continue;
                res++;
            }
            cout<<res<<"\n";
        }
        else if(a==2)
        {
            update(1,1,n,b,c);
            arr[b]=c;
        }
    }
}