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

ll arr[LEN];
int cmp(ll a, ll b)
{
    return a>b;
}

void program()
{
    int n;
    ll c;
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]-=c;
    }
    sort(arr,arr+n,cmp);
    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(i>=(n+1)/2 && arr[i]<=0) break;
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