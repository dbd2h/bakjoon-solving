#include <iostream>
#include <cmath>
#include <string>
typedef long double ld;
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    string s;
    cin>>s;
    ll p=0;
    ll count=1;
    int idx=s.size()-1;
    while(idx>=0)
    {
        if(s[idx]=='.')
        {
            idx--;
            continue;
        }
        p+=(ll)(s[idx]-'0')*count;
        count*=10;
        idx--;
    }
    count/=10;
    ll h=(ll)p/count;
    ll b=(ll)p-count*h;
    ll a=count-b;
    ll gcdV=1;
    if(a>b) gcdV=gcd(a,b);
    else gcdV=gcd(b,a);
    a/=gcdV;
    b/=gcdV;
    for(int i=1;i<=5;i++)
    {
        if(i==h) cout<<a<<" ";
        else if(i==h+1) cout<<b<<" ";
        else cout<<0<<" ";
    }
}