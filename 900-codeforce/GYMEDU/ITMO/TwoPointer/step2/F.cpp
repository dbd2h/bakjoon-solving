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

int main()
{
    int n;
    ll k;
    cin>>n>>k;
    ll arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];
    stack<ll> st1;
    stack<ll> maxSt1;
    stack<ll> minSt1;
    stack<ll> st2;
    stack<ll> maxSt2;
    stack<ll> minSt2;
    int l=0;
    int r=0;
    ll res=0;
    while(l<n)
    {
        ll maxV=0;
        ll minV=(ll)(1e18)+7;
        if(!st1.empty())
        {
            maxV=max(maxSt1.top(),maxV);
            minV=min(minSt1.top(),minV);
        }
        if(!st2.empty())
        {
            maxV=max(maxSt2.top(),maxV);
            minV=min(minSt2.top(),minV);
        }
        if(r==n || arr[r+1]-minV>k || maxV-arr[r+1]>k)
        {
            if(st1.empty())
            {
                while(!st2.empty())
                {
                    st1.push(st2.top());
                    if(maxSt1.empty()) maxSt1.push(st1.top());
                    else maxSt1.push(max(maxSt1.top(),st1.top()));
                    if(minSt1.empty()) minSt1.push(st1.top());
                    else minSt1.push(min(minSt1.top(),st1.top()));
                    st2.pop();
                    maxSt2.pop();
                    minSt2.pop();
                }
            }
            res+=(r-l);
            l++;
            st1.pop();
            maxSt1.pop();
            minSt1.pop();
            continue;
        }
        r++;
        st2.push(arr[r]);
        if(maxSt2.empty()) maxSt2.push(st2.top());
        else maxSt2.push(max(maxSt2.top(),st2.top()));
        if(minSt2.empty()) minSt2.push(st2.top());
        else minSt2.push(min(minSt2.top(),st2.top()));
    }
    cout<<res;
}