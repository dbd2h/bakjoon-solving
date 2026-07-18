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
#define LEN 200001

using namespace std;

void program()
{
    ll n;
    cin>>n;
    ll A[LEN],B[LEN];
    for(ll i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>B[i];
    }
    bool isZero=0;
    bool isOne=0;
    ll zero=0;
    ll one=0;
    for(ll i=0;i<n;i++)
    {
        if(A[i]==B[i])
        {
            if(A[i]==0) isZero=1;
            else isOne=1;
            continue;
        }
        if(A[i]==0) zero++;
        else one++;
    }
    if(one==0 && zero==0)
    {
        cout<<0<<"\n";
    }
    else if(one==0 && zero>0)
    {
        if(isZero && isOne) cout<<2<<"\n";
        else cout<<-1<<"\n";
    }
    else if(one%2==1)
    {
        cout<<1<<"\n";
    }
    else cout<<2<<"\n";
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