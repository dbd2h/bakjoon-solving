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
    ll s;
    cin>>n>>s;
    ll arr[LEN];
    for(int i=0;i<n;i++) cin>>arr[i];
    int l=-1;
    int r=-1;
    ll sumV=0;
    ll res=0;
    while(r<n)
    {
        if(sumV>s)
        {
            l++;
            res+=(r-l);
            sumV-=arr[l];
        }
        else
        {
            r++;
            if(r==n) break;
            sumV+=arr[r];
        }
    }
    while(l<n)
    {
        l++;
        res+=(r-l);
    }
    cout<<res;
}