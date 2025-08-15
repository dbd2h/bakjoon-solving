#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    long long res=1;
    for(long long i=n;i>n-k;i--)
    {
        res*=i;
    }
    for(long long j=1;j<=k;j++)
    {
        res/=j;
    }
    cout<<res;
}