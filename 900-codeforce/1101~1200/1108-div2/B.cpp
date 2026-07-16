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
    if(n==1) cout<<1;
    else if(n==2) cout<<-1;
    else
    {
        ll a=3;
        cout<<1<<" "<<2<<" ";

        for(int i=3;i<=n;i++)
        {
            cout<<a<<" ";
            a*=2;
        }
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