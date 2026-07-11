#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200005
#define INF (ll)(5e8)

using namespace std;

int arr[LEN];

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int maxV=max(arr[3]-arr[1],arr[n]-arr[n-2]);
    int minV=INF;
    for(int i=2;i<n-1;i++)
    {
        int left=arr[i-1];
        int right=arr[i+2];
        int mid=(left+right)/2;
        int res=mid-left;
        maxV=max(maxV,res);
    }
    for(int i=2;i<n;i++)
    {
        int left=arr[i-1];
        int right=arr[i+1];
        int mid=(left+right)/2;
        int res=mid-left;
        minV=min(res,minV);
    }
    cout<<maxV<<" "<<minV<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<"\n";
        program();
    }
}