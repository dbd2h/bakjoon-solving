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
int tree[LEN*8]={0};
int leftArr[LEN]={0};

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
    int resArr[LEN];
    for(int i=1;i<=n*2;i++)
    {
        int num;
        cin>>num;
        if(leftArr[num]==0)
        {
            update(1,1,n*2,i,1);
            leftArr[num]=i;
        } 
        else
        {
            resArr[num]=query(1,1,n*2,i)-query(1,1,n*2,leftArr[num]);
            update(1,1,n*2,i,1);
            update(1,1,n*2,leftArr[num],-1);
        }
    }
    for(int i=1;i<=n;i++) cout<<resArr[i]<<" ";
}