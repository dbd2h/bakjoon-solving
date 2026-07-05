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

ll tree[LEN*4]={0};
ll arr[LEN];

int cmp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first>p2.first;
}

void update(int node, int l, int r, int idx, int num)
{
    if(l==r)
    {
        tree[node]=num;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int idx)
{
    int mid=(l+r)/2;
    if(idx<l) return 0;
    else if(r<=idx) return tree[node];
    else return query(node*2,l,mid,idx)+query(node*2+1,mid+1,r,idx);
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        v.push_back({arr[i],i});
    } 
    sort(v.begin(),v.end(),cmp);
    int res[LEN];
    for(auto& p : v)
    {
        update(1,1,n,p.second,1);
        res[p.second]=query(1,1,n,p.second-1);
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}