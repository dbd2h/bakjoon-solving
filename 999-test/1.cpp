#include <iostream>

#define MOD (long long) 10e9+7

using namespace std;

int main()
{
    long long res=1;
    for(long long i=1;i<=14;i++)
    {
        res*=i;
        res%=MOD;
    }
    cout<<res<<"\n";
    long long idx=1;
    long long res2=2;
    while(idx<=14)
    {
        res2*=idx;
        res2%=MOD;
        idx++;
    }
    cout<<res2;
}
