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
    int n,k;
    cin>>n>>k;
    int arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int bit[LEN]={0};
    int l=0;
    int r=0;
    int u=0;
    ll res=0;
    while(r<=n)
    {
        if(u>k)
        {
            res+=(r-1-l);
            l++;
            int cur=arr[l];
            bit[cur]--;
            if(bit[cur]==0) u--;
        }
        else
        {
            r++;
            if(r>n) break;
            int cur=arr[r];
            if(bit[cur]==0) u++;
            bit[cur]++;
        }
    }
    while(l<=n)
    {
        res+=(r-1-l);
        l++;
    }
    cout<<res;
}