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
#define INF (ll)(1e9+7)

using namespace std;

struct Node
{
    ll sum,pre,suf,max,lazy;
};

Node tree[LEN*4];

void update(int node, int l, int r, int left, int right, ll num)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        int len=(r-l+1);
        if(num>0) tree[node]={num*len,num*len,num*len,num*len,num};
        else tree[node]={num*len,0,0,0,num};
        return;
    }
    int mid=(l+r)/2;
    ll lazy=tree[node].lazy;
    if(lazy!=INF)
    {
        int len1=(mid-l+1);
        int len2=(r-mid);
        if(lazy>0)
        {
            tree[node*2]={lazy*len1,lazy*len1,lazy*len1,lazy*len1,lazy};
            tree[node*2+1]={lazy*len2,lazy*len2,lazy*len2,lazy*len2,lazy};
        }
        else
        {
            tree[node*2]={lazy*len1,0,0,0,lazy};
            tree[node*2+1]={lazy*len2,0,0,0,lazy};
        }
        tree[node].lazy=INF;
    }
    update(node*2,l,mid,left,right,num);
    update(node*2+1,mid+1,r,left,right,num);
    Node n1=tree[node*2];
    Node n2=tree[node*2+1];
    tree[node].sum=n1.sum+n2.sum;
    tree[node].pre=max(n1.pre,n1.sum+n2.pre);
    tree[node].suf=max(n2.suf,n2.sum+n1.suf);
    tree[node].max=max(n1.max,n2.max);
    tree[node].max=max(tree[node].max,n1.suf+n2.pre);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*4;i++) tree[i]={0,0,0,0,INF};
    for(int i=0;i<m;i++)
    {
        int l,r;
        ll v;
        cin>>l>>r>>v;
        l++;
        update(1,1,n,l,r,v);
        cout<<tree[1].max<<"\n";
    }
}