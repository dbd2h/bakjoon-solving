#include <iostream>
#include <string>

using namespace std;

void dac(long long n, long long k, long long d)
{
    if(n<=0)
    {
        cout<<-1;
        return;
    }
    long long ten=1;
    for(long long i=1;i<d;i++)
    {
        ten*=10;
    }
    if(k>ten*d*9)
    {
        dac(n-ten*9, k-ten*d*9, d+1);
        return;
    };
    long long div=(k-1)/d+1;
    if(n<div)
    {
        cout<<-1;
        return;
    }
    long long num=ten+div-1;
    string s=to_string(num);
    cout<<s[(k-1)%d];
    return;
}

int main()
{
    long long n,k;
    cin>>n>>k;
    dac(n,k,1);

}