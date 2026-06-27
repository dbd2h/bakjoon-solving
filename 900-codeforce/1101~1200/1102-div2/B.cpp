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
    ll n;
    cin>>n;
    if(n==10) cout<<-1<<"\n";
    else
    {
        ll rem=n%(ll)12;
        if(rem==10) rem+=12;
        cout<<rem<<" "<<n-(rem)<<"\n";
    }
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