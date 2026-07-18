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
#define LEN 300001

using namespace std;

int main()
{
    int n,R;
    cin>>n>>R;
    int arr[LEN];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int l=1;
    int r=1;
    ll res=0;
    while(r<=n)
    {
        int dis=arr[r]-arr[l];
        if(dis<=R)
        {
            r++;
        }
        else
        {
            res+=(n-r+1);
            l++;
        }
    }
    cout<<res;
}