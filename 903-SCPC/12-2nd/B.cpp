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

struct NODE
{
    ll l;
    ll r;
    ll sumL;
    ll sumR;
};

NODE tree[LEN*4+4];
ll A[LEN];
ll B[LEN];

void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node].l=0;
        tree[node].r=0;
        tree[node].sumL=0;
        tree[node].sumR=0;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node].l=0;
    tree[node].r=0;
    tree[node].sumL=0;
    tree[node].sumR=0;
}

void update(int node, int l, int r, int idx, bool isR)
{
    if(l==r)
    {
        if(!isR)
        {
            tree[node].l++;
            tree[node].sumL+=idx;
        }
        else
        {
            tree[node].r++;
            tree[node].sumR+=idx;
        }
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,isR);
    else update(node*2+1,mid+1,r,idx,isR);
    tree[node].l=tree[node*2].l+tree[node*2+1].l;
    tree[node].sumL=tree[node*2].sumL+tree[node*2+1].sumL;
    tree[node].r=tree[node*2].r+tree[node*2+1].r;
    tree[node].sumR=tree[node*2].sumR+tree[node*2+1].sumR;
}

NODE query(int node, int l, int r, int idx)
{
    NODE cur={0,0,0,0};
    if(idx<l) return cur;
    else if(r<=idx) return tree[node];
    int mid=(l+r)/2;
    NODE n1=query(node*2,l,mid,idx);
    NODE n2=query(node*2+1,mid+1,r,idx);
    cur.l=n1.l+n2.l;
    cur.sumL=n1.sumL+n2.sumL;
    cur.r=n1.r+n2.r;
    cur.sumR=n1.sumR+n2.sumR;
    return cur;
}

void program()
{
    int n;
    cin>>n;
    build(1,1,LEN);
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++) cin>>B[i];
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll left=A[i];
        ll right=B[i];
        if(right<left)
        {
            ll c=left;
            left=right;
            right=c;
        }
        NODE everyN=query(1,1,LEN,LEN);
        NODE leftN=query(1,1,LEN,left);
        NODE rightN=query(1,1,LEN,right);
        res+=(leftN.l*left-leftN.sumL);
        res+=(everyN.sumL-leftN.sumL-(everyN.l-leftN.l)*left);
        res+=(rightN.r*right-rightN.sumR);
        res+=(everyN.sumR-rightN.sumR-(everyN.r-rightN.r)*right);
        update(1,1,LEN,left,0);
        update(1,1,LEN,right,1);
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