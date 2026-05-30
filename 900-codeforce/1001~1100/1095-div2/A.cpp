#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    ll modV=676767677;
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    ll res=0;
    if(arr[n-1]==1) res+=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1) continue;
        res+=arr[i];
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