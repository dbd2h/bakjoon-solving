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

struct Node
{
    int max, lazy;
};

Node tree[LEN*4];

void update(int node, int l,int r, int left, int right, int num)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        tree[node].max+=num;
        if(tree[node].lazy==-1) tree[node].lazy=num;
        else  tree[node].lazy+=num;
        return;
    }
    int mid=(l+r)/2;
    int lazy=tree[node].lazy;
    if(lazy!=-1)
    {
        tree[node*2].max+=lazy;
        if(tree[node*2].lazy==-1) tree[node*2].lazy=lazy;
        else tree[node*2].lazy+=lazy;
        tree[node*2+1].max+=lazy;
        if(tree[node*2+1].lazy==-1) tree[node*2+1].lazy=lazy;
        else tree[node*2+1].lazy+=lazy;
        tree[node].lazy=-1;
    }
    update(node*2,l,mid,left,right,num);
    update(node*2+1,mid+1,r,left,right,num);
    tree[node].max=max(tree[node*2].max,tree[node*2+1].max);
}

int query(int node, int l, int r, int idx, int num)
{
    if(tree[node].max<num) return -1;
    if(r<idx) return -1;
    if(l==r)
    {
        return l;
    }
    int mid=(l+r)/2;
    int lazy=tree[node].lazy;
    if(lazy!=-1)
    {
        tree[node*2].max+=lazy;
        if(tree[node*2].lazy==-1) tree[node*2].lazy=lazy;
        else tree[node*2].lazy+=lazy;
        tree[node*2+1].max+=lazy;
        if(tree[node*2+1].lazy==-1) tree[node*2+1].lazy=lazy;
        else tree[node*2+1].lazy+=lazy;
        tree[node].lazy=-1;
    }
    int res=query(node*2,l,mid,idx,num);
    if(res==-1) res=query(node*2+1,mid+1,r,idx,num);
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*4;i++) tree[i]={0,-1};
    for(int i=0;i<m;i++)
    {
        int  a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            b++;
            int num;
            cin>>num;
            update(1,1,n,b,c,num);
        }
        else if(a==2)
        {
            c++;
            int res=query(1,1,n,c,b);
            if(res==-1) cout<<-1<<"\n";
            else cout<<res-1<<"\n";
        }
    }
}