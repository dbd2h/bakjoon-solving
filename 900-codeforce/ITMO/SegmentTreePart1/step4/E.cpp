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
        tree[node]=num;
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,num);
    else update(node*2+1,mid+1,r,idx,num);
    tree[node]=tree[node*2];
    if(tree[node*2+1]!=0 && (tree[node]==0 || tree[node]>tree[node*2+1])) tree[node]=tree[node*2+1];
}

int query(int node, int l, int r, int left, int right, int num)
{
    if(tree[node]==0 || tree[node]>num) return 0;
    if(right<l || r<left) return 0;
    if(l==r)
    {
        return l;
    }
    int mid=(l+r)/2;
    int res=query(node*2,l,mid,left,right,num);
    if(res!=0) return res;
    res=query(node*2+1,mid+1,r,left,right,num);
    return res;
}

int main()
{
    int n,h;
    cin>>n>>h;
    for(int i=0;i<h;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        b++;
        if(a==1)
        {
            update(1,1,n,b,c);
        }
        else if(a==2)
        {
            int p;
            cin>>p;
            int res=0;
            while(tree[1]!=0 && tree[1]<=p)
            {
                int idx=query(1,1,n,b,c,p);
                if(idx==0) break;
                update(1,1,n,idx,0);
                res++;
            }
            cout<<res<<"\n";
        }
    }
}