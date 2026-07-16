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
    ll sumV=0;
    int res=0;
    int l=-1;
    int r=-1;
    while(r<n)
    {
        if(s>=sumV)
        {
            res=max(res,r-l);
            r++;
            if(r==n) break;
            sumV+=arr[r];
        }
        else
        {
            l++;
            sumV-=arr[l];
        }
    }
    cout<<res;
}