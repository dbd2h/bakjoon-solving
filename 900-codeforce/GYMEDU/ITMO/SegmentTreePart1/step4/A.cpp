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

int tree[LEN*4]={0};

void update(int node, int l, int r, int idx, int num)
{
    if(l==r)
    {
        if(idx%2==0) num=-num;
        tree[node]=num;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int left, int right)
{   
    int mid=(l+r)/2;
    if(r<left || right<l) return 0;
    else if(left<=l && r<=right) return tree[node];
    else return query(node*2,l,mid,left,right)+query(node*2+1,mid+1,r,left,right);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        update(1,1,n,i,num);
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int s,a,b;
        cin>>s>>a>>b;
        if(s==0)
        {
            update(1,1,n,a,b);
        }
        else
        {
            int res=query(1,1,n,a,b);
            if(a%2==0) res=-res;
            cout<<res<<"\n";
        }
    }
}