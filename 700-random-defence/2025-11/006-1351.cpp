#include <iostream>
#include <map>

using namespace std;
map<long long,long long> m;
long long recF(long long n1, long long n2, long long p, long long q)
{
    long long num1,num2;
    if(n1==0) num1=1;
    else if(m[n1]!=0) num1=m[n1];
    else
    {
        num1=recF(n1/p,n1/q,p,q);
        m[n1]=num1;
    } 
    if(n2==0) num2=1;
    else if(m[n2]!=0) num2=m[n2];
    else
    {
        num2=recF(n2/p,n2/q,p,q);
        m[n2]=num2;
    } 
    return num1+num2;
    
}

int main()
{
    
    long long n,p,q;
    cin>>n>>p>>q;
    if(n==0)
    {
        cout<<1;
        return 0;
    }
    long long res=recF(n/p,n/q,p,q);
    cout<<res;
}