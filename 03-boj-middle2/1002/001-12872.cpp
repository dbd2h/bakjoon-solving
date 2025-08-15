#include <iostream>
#include <vector>

using namespace std;

long long inv[101]={0};

long long MOD=1'000'000'007;

pair<long long, long long> gcd(long long a, long long b)
{
    long long c=a%b;
    long long n1=1;
    long long n2=-a/b;
    if(c==1)
    {
        return {n1,n2};
    }
    pair<long long,long long> p=gcd(b,c);
    long long resn1=p.second;
    long long resn2=p.second*n2+p.first;
    return {resn1,resn2};
}

long long combi(int n1, int n2)
{
    long long res=1;
    if(n1-n2<n2) n2=n1-n2;
    long long idx=n1;
    for(int i=1;i<=n2;i++)
    {
        res*=inv[i];
        res%=MOD;
        res*=idx;
        res%=MOD;
        idx--;
    }
    return res;
}

int main()
{
    int n,m,p;
    cin>>n>>m>>p;

    inv[1]=1;
    for(int i=2;i<=100;i++)
    {
        pair<long long,long long> p1=gcd(MOD,i);
        long long invV=p1.second;
        if(invV<0) invV+=MOD;
        inv[i]=invV;
    }
    long long result=0;
    bool isMinus=false;
    for(long long i=n;i>0;i--)
    {
        long long plusV=1;
        long long sub=0;
        for(int j=0;j<p;j++)
        {
            plusV*=(i-sub);
            plusV%=MOD;
            if(sub<m) sub++;
        }
        plusV*=combi(n,n-i);
        plusV%=MOD;
        if(isMinus)
        {
            result-=plusV;
            if(result<0) result+=MOD;
        }
        else
        {
            result+=plusV;
            result%=MOD;
        }
        isMinus=!isMinus;
        if(i==m) break;
    }
    cout<<result;
}