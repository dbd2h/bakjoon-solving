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

pair<int,bool> tree[LEN*4];

void update(int node, int l, int r, int left, int right)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        int len=r-l+1;
        tree[node]={len-tree[node].first,!tree[node].second};
        return;
    }
    int mid=(l+r)/2;
    if(tree[node].second)
    {   
        int len1=mid-l+1;
        int len2=r-mid;
        tree[node*2]={len1-tree[node*2].first,!tree[node*2].second};
        tree[node*2+1]={len2-tree[node*2+1].first,!tree[node*2+1].second};
        tree[node].second=false;
    }
    update(node*2,l,mid,left,right);
    update(node*2+1,mid+1,r,left,right);
    tree[node].first=tree[node*2].first+tree[node*2+1].first;
}

int query(int node, int l, int r, int num)
{
    if(tree[node].first<num) return -1;
    if(l==r)
    {
        if(tree[node].first==num) return l;
        else return -1;
    }
    int mid=(l+r)/2;
    if(tree[node].second)
    {
        int len1=mid-l+1;
        int len2=r-mid;
        tree[node*2]={len1-tree[node*2].first,!tree[node*2].second};
        tree[node*2+1]={len2-tree[node*2+1].first,!tree[node*2+1].second};
        tree[node].second=false;
    }
    int res=query(node*2,l,mid,num);
    if(res==-1) res=query(node*2+1,mid+1,r,num-tree[node*2].first);
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*4;i++) tree[i]={0,false};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        b++;
        if(a==1)
        {
            int c;
            cin>>c;
            update(1,1,n,b,c);
        }
        else if(a==2)
        {
            cout<<query(1,1,n,b)-1<<"\n";
        }
    }
}