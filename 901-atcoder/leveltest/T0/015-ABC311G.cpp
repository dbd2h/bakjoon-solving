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
#define LEN 301

using namespace std;

struct NODE
{
    int sum;
    int c;
};

NODE tree[LEN][LEN*4];
int arr[LEN][LEN];

void build(int node, int l, int r, int x)
{
    if(l==r)
    {
        tree[x][node].sum=arr[x][l];
        tree[x][node].c=0;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid,x);
    build(node*2+1,mid+1,r,x);
    tree[x][node].sum=tree[x][node*2].sum+tree[x][node*2+1].sum;
    tree[x][node].c=0;
}

void update(int node, int l, int r, int x, int idx)
{
    if(l==r)
    {
        tree[x][node].c=1;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,x,idx);
    else update(node*2+1,mid+1,r,x,idx);
    tree[x][node].c=tree[x][node*2].c+tree[x][node*2+1].c;
}

int main()
{
    int n,m;
    cin>>n>>m;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
            pq.push({arr[i][j],{i,j}});
        } 
        build(1,1,m,i);
    }
    
}