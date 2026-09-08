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
    ll x,y,k;
    cin>>x>>y>>k;
    ll res=0;
    for(ll i=0;i<k;i++)
    {
        ll xp=x+i;
        ll yp=y+i;
        if(xp*2>yp)
        {
            res+=(yp-xp)*(k-i);
            break;
        }
        res+=(yp%xp);
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