#include <iostream>
#include <vector>
using namespace std;

long long inv[400000]={0};
long long powArr[70]={0};
long long invPowArr[70]={0};

pair<long long,long long> gcd(long long a, long long b)
{
    long long c=a%b;
    if(c==1) return {1,-a/b};
    pair<long long,long long> p=gcd(b,c);
    long long n1=p.second;
    long long n2=p.first-a/b*p.second;
    return {n1,n2};
}

void multi(long long n, long long *result, bool isInv, int idx, long long m)
{
    if(n==0) return;
    if(isInv)
    {
        if(n%2==1)
        {
            (*result)*=invPowArr[idx];
            (*result)%=m;
        }
        multi(n/2,result,isInv,idx+1,m);
    }
    else
    {
        if(n%2==1)
        {
            (*result)*=powArr[idx];
            (*result)%=m;
            
        }
        multi(n/2,result,isInv,idx+1,m);
    }
}

int main()
{
    long long n,k,m;
    cin>>n>>k>>m;
    long long nCount=0;
    long long kCount=0;
    long long nStart=n;
    long long nEnd=n-k;
    long long kStart=k;
    while(nStart || nEnd || kStart)
    {
        nStart/=m;
        nCount+=nStart;
        nEnd/=m;
        nCount-=nEnd;
        kStart/=m;
        kCount+=kStart;
    }
    if(nCount>kCount)
    {
        cout<<0;
        return 0;
    }
    inv[1]=1;
    for(long long i=2;i<m;i++)
    {
        pair<long long,long long> p=gcd(m,i);
        inv[i]=p.second;
        if(inv[i]<0) inv[i]+=m;
    }
    long long mulV=1;
    long long mulV2=1;
    for(int i=1;i<m;i++)
    {
        mulV*=i;
        mulV%=m;
        mulV2*=inv[i];
        mulV2%=m;
    }
    powArr[0]=mulV;
    invPowArr[0]=mulV2;
    for(int i=1;i<70;i++)
    {
        powArr[i]=powArr[i-1]*powArr[i-1];
        powArr[i]%=m;
        invPowArr[i]=invPowArr[i-1]*invPowArr[i-1];
        invPowArr[i]%=m;
    }
    long long result=1;
    nStart=n;
    nEnd=n-k;
    while(true)
    {
        long long idx=nStart%m;
        for(long long i=1;i<=idx;i++)
        {
            result*=i;
            result%=m;
        }
        nStart-=idx;
        if(nStart==0) break;
        multi(nStart/m,&result,0,0,m);
        nStart/=m;
    }
    while(true)
    {
        long long idx=nEnd%m;
        for(long long i=1;i<=idx;i++)
        {
            result*=inv[i];
            result%=m;
        }
        nEnd-=idx;
        if(nEnd==0) break;
        multi(nEnd/m,&result,1,0,m);
        nEnd/=m;
    }
    while(true)
    {
        long long idx=k%m;
        for(long long i=1;i<=idx;i++)
        {
            result*=inv[i];
            result%=m;
        }
        k-=idx;
        if(k==0) break;
        multi(k/m,&result,1,0,m);
        k/=m;
    }
    cout<<result;
}