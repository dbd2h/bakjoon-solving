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
#define LEN 3001
#define MOD (ll)(998244353)

using namespace std;

struct NODE
{
    ll dp[LEN];
};

NODE tree[LEN*4];
int arr[LEN];

void build(int node, int l, int r, int s)
{
    if(l==r)
    {
        for(int i=0;i<=s;i++) tree[node].dp[i]=0;
        tree[node].dp[0]=1;
        tree[node].dp[arr[l]]=1;
        return;
    }
    int mid=(l+r)/2;
    if(l<mid) build(node*2,l,mid,s);
    else build(node*2+1,mid+1,r,s);
    for(int i=0;i<=s;i++)
    {
        
    }
}

int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>arr[i];
    
}