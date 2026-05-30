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
    ll arr[200000];
    for(int i=0;i<n;i++) cin>>arr[i];
    int res=0;
    for(int i=n-1;i>=0;i--)
    {
        if(i!=n-1)
        {
            if(arr[i+1]>0) arr[i]+=arr[i+1];
        }
        if(arr[i]>0) res++;
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