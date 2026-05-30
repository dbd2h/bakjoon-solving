#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    int n;
    cin>>n;
    int arr[200000];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]<=arr[i+1]) continue;
        k=max(k,arr[i]-arr[i+1]);
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]<=arr[i+1]) continue;
        arr[i+1]+=k;
        if(arr[i]<=arr[i+1]) continue;
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}