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
#define LEN 500001

using namespace std;

int arr[LEN];
int tree[LEN*4]={0};
int bit[LEN]={0};
int res[LEN];

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
    if(idx<l) return 0;
    else if(r<=idx) return tree[node];
    int mid=(l+r)/2;
    return query(node*2,l,mid,idx)+query(node*2+1,mid+1,r,idx);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        bit[arr[i]]++;
    } 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=1;i<=m;i++)
    {
        if(bit[i]>0)
        {
            update(1,1,m,i,0);
            pq.push({bit[i],i});
        } 
        else update(1,1,m,i,1);
    }
    int q;
    cin>>q;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> ans;
    for(int i=1;i<=q;i++)
    {
        ll num;
        cin>>num;
        ans.push({num,i});
    }
    int loop=0;
    ll order=0;
    while(!ans.empty())
    {
        ll num=ans.top().first;
        int idx=ans.top().second;
        ans.pop();
        if(num<=n)
        {
            res[idx]=arr[num];
            continue;
        }
        if(order==0) order=n;
        if(pq.empty())
        {
            ll dis=(num-order-1)%m+1;
            res[idx]=dis;
            continue;
        }
        bool isCon=false;
        while(true)
        {
            int len=query(1,1,m,m);
            if(order+len>=num) break;
            loop++;
            order+=len;
            while(!pq.empty())
            {
                if(pq.top().first>loop) break;
                update(1,1,m,pq.top().second,1);
                pq.pop();
            }
            if(pq.empty())
            {
                ans.push({num,idx});
                isCon=true;
                break;
            } 
        }
        if(isCon) continue;
        int l=1;
        int r=m;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int cur=query(1,1,m,mid);
            if(order+cur<num) l=mid+1;
            else r=mid-1;
        }
        res[idx]=r+1;
    }
    for(int i=1;i<=q;i++)
    {
        cout<<res[i]<<"\n";
    }
}