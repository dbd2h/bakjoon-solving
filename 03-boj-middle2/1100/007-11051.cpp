#include <iostream>
#include <vector>

using namespace std;

long long inv[1001]={0};
long long MOD=10007;

pair<long long,long long> gcd(long long a, long long b)
{
    long long c=a%b;
    if(c==1) return {1,-a/b};
    pair<long long,long long> p=gcd(b,c);
    long long n1=p.second;
    long long n2=p.first-(a/b)*p.second;
    return {n1,n2};

}

int main()
{
    int n,k;
    cin>>n>>k;
    inv[1]=1;
    for(long long i=2;i<=n;i++)
    {
        pair<long long,long long> p=gcd(MOD,i);
        inv[i]=p.second;
        if(inv[i]<0) inv[i]+=MOD;
    }
    long long res=1;
    for(long long i=n;i>n-k;i--)
    {
        res*=i;
        res%=MOD;
    }
    for(int i=1;i<=k;i++)
    {
        res*=inv[i];
        res%=MOD;
    }
    cout<<res;
}