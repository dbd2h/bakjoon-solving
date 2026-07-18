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
    ll n,k,m;
    cin>>n>>k>>m;
    if(k>m)
    {
        cout<<"NO\n";
        return;
    }
    else cout<<"YES\n";
    ll num=m-k+1;
    cout<<num<<" ";
    for(ll i=1;i<n;i++) cout<<1<<" ";
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