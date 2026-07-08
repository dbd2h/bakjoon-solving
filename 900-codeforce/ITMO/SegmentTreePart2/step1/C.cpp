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

pair<int,int> tree[LEN*4];

void update(int node, int l, int r, int left, int right, int num, int idx)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        tree[node]={num,idx};
        return;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,left,right,num,idx);
    update(node*2+1,mid+1,r,left,right,num,idx);
}

pair<int,int> query(int node, int l, int r, int idx)
{
    if(l==r)
    {
        return tree[node];
    }
    int mid=(l+r)/2;
    pair<int,int> res;
    if(idx<=mid) res=query(node*2,l,mid,idx);
    else res=query(node*2+1,mid+1,r,idx);
    if(res.second>tree[node].second) return res;
    else return tree[node];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<LEN*4;i++)
    {
        tree[i]={0,0};
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        b++;
        if(a==1)
        {
            int c,d;
            cin>>c>>d;
            update(1,1,n,b,c,d,i);
        }
        else if(a==2)
        {
            cout<<query(1,1,n,b).first<<"\n";
        }
    }
}