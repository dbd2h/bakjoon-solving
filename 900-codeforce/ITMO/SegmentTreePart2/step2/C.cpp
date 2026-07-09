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

pair<ll,ll> tree[LEN*4]; // xorNum, xorRes
ll retNum=1073741823;

void update(int node, int l, int r, int left, int right, ll num)
{
    if(right<l || r<left) return;
    else if(left<=l && r<=right)
    {
        tree[node]={(tree[node].first | num),(tree[node].second | num)};
        return;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,left,right,num);
    update(node*2+1,mid+1,r,left,right,num);
    tree[node].second=(tree[node*2].second & tree[node*2+1].second) | tree[node].first;
}

ll query(int node, int l, int r, int left, int right)
{
    if(right<l || r<left) return retNum;
    else if(left<=l && r<=right) return tree[node].second;
    int mid=(l+r)/2;
    ll res=query(node*2,l,mid,left,right) & query(node*2+1,mid+1,r,left,right);
    return res | tree[node].first;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*4;i++) tree[i]={0,0};
    for(int i=0;i<m;i++)
    {
        int a,l,r;
        cin>>a>>l>>r;
        l++;
        if(a==1)
        {
            ll num;
            cin>>num;
            update(1,1,n,l,r,num);
        }
        else if(a==2)
        {
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
}