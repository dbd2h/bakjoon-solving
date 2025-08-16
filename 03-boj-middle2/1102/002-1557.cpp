#include <iostream>
#include <vector>

using namespace std;

bool prime[50000]={0};
vector<long long> primeV;

void powss(long long *res, long long middle, int c, int count, long long value, int idx)
{
    if(c==count)
    {
        if(count%2==1)
        {
            *res -= (middle/value);
        }
        else
        {
            *res += (middle/value);
        }
        return;
    }
    for(int i=idx;i<primeV.size();i++)
    {
        if(value*primeV[i]*primeV[i]>middle) return;
        powss(res,middle,c+1,count,value*primeV[i]*primeV[i],i+1);
    }

}

long long binarySearch(long long l, long long r, long long n)
{
    if(l>r) return -1;
    long long middle=(l+r)/2;
    long long nValue=middle;
    long long nValuep=middle-1;
    for(int i=1;i<=7;i++)
    {
        powss(&nValue,middle,0,i,1,0);
        powss(&nValuep,middle-1,0,i,1,0);
    }
    if(nValue<n) return binarySearch(middle+1,r,n);
    else if(nValuep<n) return middle;
    else return binarySearch(l,middle-1,n);
}

int main()
{
    long long n;
    cin>>n;
    for(long long i=2;i<50000;i++)
    {
        if(prime[i]) continue;
        primeV.push_back(i);
        long long idx=i*2;
        while(idx<50000)
        {
            prime[idx]=1;
            idx+=i;
        }
    }
    cout<<binarySearch(1,n*2,n);
}