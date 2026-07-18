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

int main()
{
    int n;
    ll s;
    cin>>n>>s;
    ll arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int l=0;
    int r=0;
    ll sumV=0;
    ll res=0;
    ll len=0;
    while(l<n)
    {
        if(sumV>s)
        {
            len-=(r-l);
            res+=len;
            l++;
            sumV-=arr[l];
        }
        else
        {
            if(r==n)
            {
                res+=len;
                len-=(r-l);
                l++;
                continue;
            }
            r++;
            len+=(r-l);
            sumV+=arr[r];
        }
    }
    cout<<res;
}