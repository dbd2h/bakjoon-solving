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
    int n,s;
    cin>>n>>s;
    int arr[LEN][2];
    for(int i=1;i<=n;i++) cin>>arr[i][0];
    for(int i=1;i<=n;i++) cin>>arr[i][1];
    int l=0;
    int r=0;
    ll w=0;
    ll res=0;
    ll c=0;
    while(r<=n)
    {
        if(w<=s)
        {
            res=max(res,c);
            r++;
            if(r>n) break;
            w+=arr[r][0];
            c+=arr[r][1];
        }
        else
        {
            l++;
            w-=arr[l][0];
            c-=arr[l][1];
        }
    }
    cout<<res;
}