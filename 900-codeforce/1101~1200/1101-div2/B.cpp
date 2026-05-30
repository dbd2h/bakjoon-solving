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
    ll h=arr[0];
    ll sumV=0;
    for(int i=0;i<n;i++)
    {
        sumV+=arr[i];
        ll div=sumV/(i+1);
        h=min(h,div);
        cout<<h<<" ";
    }
    cout<<"\n";
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