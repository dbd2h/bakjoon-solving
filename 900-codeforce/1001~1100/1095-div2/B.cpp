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

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

void program()
{
    int n;
    cin>>n;
    int arr[200000];
    for(int i=0;i<n;i++) cin>>arr[i];
    int res=0;
    for(int i=0;i<n-1;i++)
    {
        int gcdV=gcd(arr[i],arr[i+1]);
        if(abs(arr[i]-arr[i+1])==gcdV) res++;
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