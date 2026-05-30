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
    int n;
    cin>>n;
    int arr[101];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int midI=(n-1)/2;
    int res=0;
    for(int i=0;i<=midI;i++)
    {
        if(arr[i]==arr[midI] && arr[n-1-i]==arr[midI]) break;
        res++;
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