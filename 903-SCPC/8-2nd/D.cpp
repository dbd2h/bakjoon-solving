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
#define LEN 257

using namespace std;

struct NODE
{
    int min;
    int max;
};

int arr[LEN][LEN];
NODE tree[LEN][LEN*4];

void build(int node, int l, int r, int idx)
{
    if(l==r)
    {
        tree[idx][node].max=arr[idx][l];
        tree[idx][node].min=arr[idx][l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid,idx);
    build(node*2+1,mid+1,r,idx);
    tree[idx][node].max=max(tree[idx][node*2].max,tree[idx][node*2+1].max);
    tree[idx][node].min=min(tree[idx][node*2].min,tree[idx][node*2+1].min);
}

pair<int,int> query(int node, int l, int r, int idx, int left, int right)
{
    if(right<l || r<left) return {0,0};
    else if(left<=l && r<=right) return {tree[idx][node].max,tree[idx][node].min};
    int mid=(l+r)/2;
    pair<int,int> p1,p2;
    p1=query(node*2,l,mid,idx,left,right);
    p2=query(node*2+1,mid+1,r,idx,left,right);
    return {max(p1.first,p2.first),min(p1.second,p2.second)};
}

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>arr[i][j];
        build(1,1,n,i);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int befMax=-1;
            int befMin=-1;
            int l=1;
            int isL=-1;
            for(int idx=1;idx<=n;idx++)
            {
                pair<int,int> p=query(1,1,n,idx,i,j);
                int maxV=p.first;
                int minV=p.second;
                if(befMax!=-1)
                {
                    maxV=max(befMax,maxV);
                    minV=min(befMin,minV);
                }
                if(maxV-minV!=(j-i+1)*idx)
                {
                    l=idx+1;
                    continue;
                }
                
            }
        }
    }
}   

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}