#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 100002

using namespace std;
ll tree[LEN*4]={0};

void update(int node, int l, int r, int idx, ll num)
{
    if(l==r)
    {
        tree[node]+=num;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node, int l, int r, int idx)
{
    int mid=(l+r)/2;
    if(idx<l) return 0;
    else if(r<=idx) return tree[node];
    else return query(node*2,l,mid,idx)+query(node*2+1,mid+1,r,idx);
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
            int c;
            ll num;
            cin>>c>>num;
            update(1,1,n+1,b,num);
            update(1,1,n+1,c+1,-num);
        }
        else 
        {
            ll res=query(1,1,n+1,b);
            cout<<res<<"\n";
        }
    }
}
