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
#define LEN 2001
#define MOD (ll)998244353

using namespace std;

int arr[LEN];
int maxArr[LEN];
int countArr[LEN];
int minArr[LEN];

ll powerF(int cur, ll mul)
{
    if(cur==0) return 1;
    if(mul==0) return 0;
    ll ret=1;
    while(cur)
    {
        if(cur%2==1) ret*=mul;
        ret%=MOD;
        mul*=mul;
        mul%=MOD;
        cur/=2;
    }
    return ret;
}

int main()
{
    int n,m;
    cin>>n>>m;
    maxArr[n]=1;
    countArr[0]=0;
    minArr[0]=m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        minArr[i]=minArr[i-1];
        if(arr[i]!=-1) minArr[i]=min(minArr[i],arr[i]);
        countArr[i]=countArr[i-1];
        if(arr[i]==-1) countArr[i]++;
    }
    for(int i=n-1;i>=1;i--)
    {
        maxArr[i]=maxArr[i+1];
        maxArr[i]=max(maxArr[i],arr[i+1]);
    }
    ll res=1;
    if(countArr[n]>0) res=powerF(countArr[n],m);
    for(int i=1;i<=n-1;i++)
    {
        int c1=countArr[i];
        int c2=countArr[n]-c1;
        if(minArr[i]<=maxArr[i]) continue;
        if(c1==0)
        {
            if(c2==0)
            {
                if(minArr[i]>maxArr[i]) res++;
                continue;
            }
            res+=powerF(c2,minArr[i]-1);
            res%=MOD;
            continue;
        }
        else if(c2==0)
        {
            res+=powerF(c1,m-maxArr[i]);
            continue;
        }
        for(int j=m;j>maxArr[i];j--)
        {
            ll cur1=powerF(c1,m-j+1);
            if(m-j>0) cur1-=powerF(c1,m-j);
            cur1+=MOD;
            cur1%=MOD;
            ll cur2=powerF(c2,min(minArr[i]-1,j-1));
            res+=cur1*cur2;
            res%=MOD;
        }
    }
    cout<<res;
}