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

using namespace std;

void program()
{
    ll n;
    cin>>n;
    ll arr[100];
    ll p=0;
    ll m=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1) p++;
        else m++;
    }
    if(n%2==1)
    {
        cout<<"NO\n";
        return;
    }
    if(abs(p-m)%4==0) cout<<"YES\n";
    else cout<<"NO\n";

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