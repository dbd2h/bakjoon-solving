#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200001

using namespace std;

struct mat
{
    int a,b,c,d;
};

mat tree[LEN*4];
mat arr[LEN];

mat product(mat m1, mat m2, int r)
{
    int a=m1.a*m2.a+m1.b*m2.c;
    int b=m1.a*m2.b+m1.b*m2.d;
    int c=m1.c*m2.a+m1.d*m2.c;
    int d=m1.c*m2.b+m1.d*m2.d;
    mat res={a%r,b%r,c%r,d%r};
    return res;
}

void build(int node, int l, int r, int mod)
{
    if(l==r)
    {
        tree[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid,mod);
    build(node*2+1,mid+1,r,mod);
    tree[node]=product(tree[node*2],tree[node*2+1],mod);
}

mat query(int node, int l, int r, int left, int right, int mod)
{
    int mid=(l+r)/2;
    if(right<l || r<left) return {1,0,0,1};
    else if(left<=l && r<=right) return tree[node];
    else return product(query(node*2,l,mid,left,right,mod),query(node*2+1,mid+1,r,left,right,mod),mod);
}

int main()
{
    int r,n,m;
    cin>>r>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        arr[i]={a%r,b%r,c%r,d%r};
    }
    build(1,1,n,r);
    for(int i=0;i<m;i++)
    {
        int le,ri;
        cin>>le>>ri;
        mat res=query(1,1,n,le,ri,r);
        cout<<res.a<<" "<<res.b<<"\n"<<res.c<<" "<<res.d<<"\n\n";
    }
}