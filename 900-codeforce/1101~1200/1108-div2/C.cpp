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
#define MOD (ll)(1e9+7)

using namespace std;

void program()
{
    int n;
    cin>>n;
    ll res=1;
    int arr[LEN];
    map<int,bool> m;
    ll mul=1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(m[arr[i]]) res=res*2%MOD;
        else
        {
            if(m[-1]==1 && m[arr[i]-1]==1) mul++;
            m[arr[i]]=1;
        } 
    }
    res*=mul;
    res%=MOD;
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