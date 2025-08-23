#include <iostream>
#include <vector>
#define LEN 1000000

using namespace std;

vector<long long> v;

void combi(long long *result, long long n, int idx, int c, long long mulV)
{
    if(v.size()==idx)
    {
        if(c==0) return;
        if(c%2==1) *result -= (n/mulV);
        else *result += (n/mulV);
        return;
    }
    combi(result,n,idx+1,c,mulV);
    combi(result,n,idx+1,c+1,mulV*v[idx]);
}

int main()
{
    long long n;
    cin>>n;
    bool prime[LEN]={0};
    for(int i=2;i<LEN;i++)
    {
        if(prime[i]) continue;
        for(int j=i*2;j<LEN;j+=i)
        {
            prime[j]=true;
        }
    }
    long long nc=n;
    for(long long i=2;i<LEN;i++)
    {
        if(prime[i]) continue;
        if(nc%i==0) v.push_back(i);
        else continue;
        while(nc%i==0)
        {
            nc/=i;
        }
    }
    if(nc!=1)
    {
        v.push_back(nc);
    }
    long long result=n;
    combi(&result,n,0,0,1);
    cout<<result;
}