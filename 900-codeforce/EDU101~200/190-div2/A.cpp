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
    ll n,a,b;
    cin>>n>>a>>b;
    ll res=0;
    if(a*3<b)
    {
        res=a*n;
    }
    else
    {
        ll rem=n%3;
        res=(n/3)*b;
        if(a*rem>=b)
        {
            res+=b;
        }
        else res+=(a*rem);
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