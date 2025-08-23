#include <iostream>
#include <vector>
#define MOD (long long) 1'000'000'007

using namespace std;

pair<long long,long long> gcd(long long a, long long b)
{
    long long c=a%b;
    if(c==1) return {1,-a/b};
    pair<long long,long long> p=gcd(b,c);
    long long n1=p.second;
    long long n2=p.first-a/b*p.second;
    return {n1,n2};
}



int main()
{
    long long n,k;
    cin>>n>>k;
    long long inv[4000001]={0};
    inv[1]=1;
    for(long long i=2;i<=n;i++)
    {
        pair<long long,long long>p=gcd(MOD,i);
        inv[i]=p.second;
        if(inv[i]<0) inv[i]+=MOD;
    }
    long long result=1;
    for(long long i=n;i>n-k;i--)
    {
        result*=i;
        result%=MOD;
    }
    for(long long i=1;i<=k;i++)
    {
        result*=inv[i];
        result%=MOD;
    }
    cout<<result;
}