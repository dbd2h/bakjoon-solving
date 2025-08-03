#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

void leftAndDown()
{
    long long a,b,k;
    cin>>a>>b>>k;
    long long gcdV;
    if(a>b) gcdV=gcd(a,b);
    else gcdV=gcd(b,a);
    a=a/gcdV;
    b=b/gcdV;
    if(a<=k && b<=k) cout<<1;
    else cout<<2;
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        leftAndDown();
    }
}