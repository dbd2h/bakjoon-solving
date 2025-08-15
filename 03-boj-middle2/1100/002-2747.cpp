#include <iostream>

using namespace std;
long long fibonacci[46]={0};

long long fibo(int n)
{
    if(n==0 || fibonacci[n]!=0) return fibonacci[n];
    if(n==0) return 0;
    if(n==1) return 1;
    fibonacci[n]=fibo(n-1)+fibo(n-2);
    return fibonacci[n];
}

int main()
{
    int n;
    cin>>n;
    fibonacci[1]=1;
    cout<<fibo(n);
    
}