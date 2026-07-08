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

void update(int node, int l, int r, int left, int right, int num)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        tree[node]=max(tree[node],num);
        return;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,left,right,num);
    update(node*2+1,mid+1,r,left,right,num);
}

int query(int node, int l, int r, int idx)
{
    if(l==r)
    {
        return tree[node];
    }
    int mid=(l+r)/2;
    if(idx<=mid) return max(tree[node],query(node*2,l,mid,idx));
    else return max(tree[node],query(node*2+1,mid+1,r,idx));
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        b++;
        if(a==1)
        {
            int c,d;
            cin>>c>>d;
            update(1,1,n,b,c,d);
        }
        else if(a==2)
        {
            cout<<query(1,1,n,b)<<"\n";
        }
    }
}