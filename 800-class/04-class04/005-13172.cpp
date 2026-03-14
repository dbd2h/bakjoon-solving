#include <iostream>
#include <vector>

using namespace std;

pair<long long,long long> gcd(long long a, long long b)
{
    if(a%b==1) return {1,-a/b};
    pair<long long,long long> p=gcd(b,a%b);
    long long p1=p.second;
    long long p2=p.first+p.second*-(a/b);
    return {p1,p2};
}

int main()
{
    int m;
    cin>>m;
    long long res=0;
    long long rem=1'000'000'007;
    for(int i=0;i<m;i++)
    {
        long long n,s;
        cin>>n>>s;
        long long cur= (int) 1;
        if(n!=1) cur=(gcd(rem,(long long)n).second+rem)%rem;
        cur*=s;
        cur%=rem;
        res+=cur;
    }
    cout<<res%rem;
}