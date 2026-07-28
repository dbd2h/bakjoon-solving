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
    int n;
    cin>>n;
    int arr[101];
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(n%2==1)
    {
        cout<<"NO\n";
        return;
    }
    int l=1e9;
    int r=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            if(l>=arr[i]) l=arr[i]-1;
        }
        else
        {
            if(r<=arr[i]) r=arr[i]+1;
        }
    }
    if(l<r) cout<<"NO\n";
    else cout<<"YES\n";
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