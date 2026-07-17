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
    ll res=0;
    ll sumV=0;
    while(r<n)
    {
        if(sumV>=s)
        {
            l++;
            sumV-=arr[l];
        }
        else
        {
            res+=(l+1);
            r++;
            if(r==n) break;
            sumV+=arr[r];
        }
    }
    cout<<res;
}