#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define MOD (ll)(1e9+7)
#define LEN 200001

using namespace std;

struct MATRIX
{
    ll mat[2][2];
    MATRIX()
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++) mat[i][j]=0;
        }
    }
};

MATRIX tree[LEN*4];

void update(int node, int l, int r, int idx, char c)
{
    if(l==r)
    {
        if(c=='?')
        {
            tree[node].mat[0][0]=19;
            tree[node].mat[0][1]=7;
            tree[node].mat[1][0]=6;
            tree[node].mat[1][1]=20;
        }
        else if(c=='H')
        {
            tree[node].mat[0][0]=1;
            tree[node].mat[0][1]=0;
            tree[node].mat[1][0]=1;
            tree[node].mat[1][1]=0;
        }
        else if(c=='S' || c=='D')
        {
            tree[node].mat[0][0]=0;
            tree[node].mat[0][1]=1;
            tree[node].mat[1][0]=0;
            tree[node].mat[1][1]=1;
        }
        else if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        {
            tree[node].mat[0][0]=0;
            tree[node].mat[0][1]=1;
            tree[node].mat[1][0]=1;
            tree[node].mat[1][1]=0;
        }
        else 
        {
            tree[node].mat[0][0]=1;
            tree[node].mat[0][1]=0;
            tree[node].mat[1][0]=0;
            tree[node].mat[1][1]=1;
        }
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid) update(node*2,l,mid,idx,c);
    else update(node*2+1,mid+1,r,idx,c);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ll num=0;
            for(int k=0;k<2;k++)
            {
                num+=tree[node*2].mat[i][k]*tree[node*2+1].mat[k][j];
                num%=MOD;
            }
            tree[node].mat[i][j]=num;
        }
    }
}

int main()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        update(1,1,n,i+1,s[i]);
    }
    cout<<tree[1].mat[0][0]<<"\n";
    for(int i=0;i<q;i++)
    {
        int idx;
        char c;
        cin>>idx>>c;
        update(1,1,n,idx,c);
        cout<<tree[1].mat[0][0]<<"\n";
    }
}