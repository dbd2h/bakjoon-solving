#include <iostream>

using namespace std;

int main()
{
    long long n;
    long long period=1500000;
    long long MOD=1000000;
    cin>>n;
    n%=period;
    long long fibonacci[1500001]={0};
    fibonacci[1]=1;
    for(int i=2;i<=n;i++)
    {
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
        fibonacci[i]%=MOD;
    }
    cout<<fibonacci[n];
}