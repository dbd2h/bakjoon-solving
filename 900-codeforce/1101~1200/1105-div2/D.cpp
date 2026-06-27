#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 1000001

using namespace std;

int m(int n, int i)
{
    return (i-1)%n+1;
}

void program()
{
    ll n,d;
    cin>>n>>d;
    ll sumArr[LEN];
    ll arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];
    sumArr[0]=0;
    for(int i=1;i<=n;i++) sumArr[i]=sumArr[i-1]+arr[i];
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int l=i+d;
        int r=i-d;
        ll sumV=(d*2)*arr[i];
        sumV-=(sumArr[m(n,l)]-sumArr[i]);
        if(l>n) sumV-=(sumArr[n]);
        sumV-=(sumArr[i-1]-sumArr[m(n,r+n)-1]);
        if(r<=0) sumV-=(sumArr[n]);
        if(sumV>0) res+=sumV;
    }
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}