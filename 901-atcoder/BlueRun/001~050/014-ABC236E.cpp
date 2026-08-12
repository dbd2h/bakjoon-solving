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
#define LEN 100001

using namespace std;

int arr[LEN];
lld kArr[LEN];
lld dp[LEN];
ll kArr2[LEN];
ll dp2[LEN];

lld bs(int n, lld l, lld r)
{
    lld mid=(l+r)/2;
    if(r-l<1e-4) return mid;
    for(int i=1;i<=n;i++)
    {
        kArr[i]=arr[i]-mid;
    }
    dp[1]=kArr[1];
    dp[2]=max(dp[1]+kArr[2],kArr[2]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=kArr[i];
        dp[i]+=max(dp[i-1],dp[i-2]);
    }
    lld res=max(dp[n],dp[n-1]);
    if(res>=0) return bs(n,mid,r);
    else return bs(n,l,mid);
}

lld bs2(int n, int l, int r)
{
    if(l>r)
    {
        int ret=0;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]<=l-1 && ret<arr[i]) ret=arr[i];
            
        }
        return ret;
    }
    int mid=(l+r)/2;
    for(int i=1;i<=n;i++)
    {
        kArr2[i]=(arr[i]>=mid ? 1 : -1);
    }
    dp2[1]=kArr2[1];
    dp2[2]=max(dp2[1]+kArr2[2],kArr2[2]);
    for(int i=3;i<=n;i++)
    {
        dp2[i]=kArr2[i];
        dp2[i]+=max(dp2[i-1],dp2[i-2]);
    }
    ll res=max(dp2[n],dp2[n-1]);
    if(res>0) return bs2(n,mid+1,r);
    else return bs2(n,l,mid-1);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cout<<fixed;
    cout.precision(7);
    cout<<bs(n,1,1e9)<<"\n";
    cout.precision(0);
    cout<<bs2(n,1,1e9)<<"\n";
}