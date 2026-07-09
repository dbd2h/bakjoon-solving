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

pair<int,int> tree[LEN*4]; // min, lazy

void update(int node, int l, int r, int left, int right, int num)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        tree[node]={num,num};
        return;
    }
    int mid=(l+r)/2;
    int lazy=tree[node].second;
    if(lazy!=-1)
    {
        tree[node*2]={lazy,lazy};
        tree[node*2+1]={lazy,lazy};
        tree[node].second=-1;
    }
    update(node*2,l,mid,left,right,num);
    update(node*2+1,mid+1,r,left,right,num);
    tree[node].first=min(tree[node*2].first,tree[node*2+1].first);
}

int query(int node, int l, int r, int left, int right)
{
    if(right<l || r<left) return INF;
    else if(left<=l && r<=right) return tree[node].first;
    int mid=(l+r)/2;
    int lazy=tree[node].second;
    if(lazy!=-1)
    {
        tree[node*2]={lazy,lazy};
        tree[node*2+1]={lazy,lazy};
        tree[node].second=-1;
    }
    return min(query(node*2,l,mid,left,right),query(node*2+1,mid+1,r,left,right));
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*4;i++) tree[i]={0,-1};
    for(int i=0;i<m;i++)
    {
        int a,l,r;
        cin>>a>>l>>r;
        l++;
        if(a==1)
        {
            int v;
            cin>>v;
            update(1,1,n,l,r,v);
        }
        else if(a==2)
        {
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
}