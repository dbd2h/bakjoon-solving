#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 5001

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[LEN];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    ll res=0;
    for(int i=0;i<n-2;i++)
    {
        int cur=k-arr[i];
        int l=i+1;
        int r=i+2;
        while(r<n)
        {
            if(arr[l]+arr[r]==cur) res++;
            if(arr[l]+arr[r]<=cur) r++;
            else l++;
            if(l==r) r++;
        }
        l++;
        while(l<r)
        {
            if(arr[l]+arr[r-1]==cur) res++;
            else if(arr[l]+arr[r-1]>cur) break;
            l++;
        }
    }
    cout<<res;
}