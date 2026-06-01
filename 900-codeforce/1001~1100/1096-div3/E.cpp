#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 200001

using namespace std;

void program()
{
    int n;
    cin>>n;
    int arr[LEN];
    for(int i=0;i<n;i++) cin>>arr[i];
    int idx=n-1;
    int maxV=0;
    int cur=n-1;
    int curSum=0;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[cur]<=arr[i])
        {
            curSum++;
        }
        else
        {
            if(maxV<curSum)
            {
                idx=cur;
                maxV=curSum;
            }
            cur=i;
            curSum=0;
        }
    }
    if(maxV<curSum)
    {
        idx=cur;
        maxV=curSum;
    }
    arr[idx]--;
    ll res=0;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<=arr[i+1]) continue;
        res+=(ll)(arr[i]-arr[i+1]);
        arr[i]=arr[i+1];
    }
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}