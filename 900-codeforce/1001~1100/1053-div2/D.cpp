#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

long long MOD=998244353;
long long rev[200001];

pair<long long, long long> gcd(int a, int b)
{
    int c=a%b;
    if(c==1) return {1,-a/b};
    pair<long long, long long> p=gcd(b,c);
    long long d=-a/b;
    long long p1=p.second;
    long long p2=p.second*d+p.first;
    return {p1,p2};
}

void program()
{
    int n;
    cin>>n;
    int arr[200001];
    bool isF=false;
    int sumV=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sumV+=arr[i];
        if(i*2>=n && arr[i]!=0) isF=true;
    }
    if(isF || sumV!=n)
    {
        cout<<0<<"\n";
        return;
    }
    long long result=1;
    long long rem=2;
    if(n%2==1) rem=1;
    for(int i=n/2;i>=0;i--)
    {
        if(n%2==0 && i==n/2) continue;
        if(arr[i]>rem)
        {
            cout<<0<<"\n";
            return;
        }
        if(arr[i]==0)
        {
            rem+=2;
            continue;
        }
        if(arr[i]==rem)
        {
            rem=2;
            continue;
        }
        for(int j=1;j<=arr[i];j++)
        {
            result*=(rem--);
            result%=MOD;
            result*=rev[j];
            result%=MOD;
        }
        rem+=2;
    }
    cout<<result<<"\n";
}

int main()
{
    rev[1]=1;
    for(int i=2;i<=200000;i++)
    {
        pair<long long,long long> p=gcd(MOD,i);
        rev[i]=p.second;
        if(rev[i]<0) rev[i]+=MOD;
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}