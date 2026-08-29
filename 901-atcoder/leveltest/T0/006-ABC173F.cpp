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

using namespace std;

int main()
{
    int n;
    cin>>n;
    ll res=0;
    ll sumV=0;
    for(int i=1;i<=n;i++)
    {
        sumV+=i;
        res+=sumV;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
        {
            int c=a;
            a=b;
            b=c;
        }
        ll cur=1;
        cur*=a;
        cur*=(n-b+1);
        res-=cur;
    }
    cout<<res;
}