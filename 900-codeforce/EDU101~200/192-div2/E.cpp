#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    ll l,r,n;
    cin>>l>>r>>n;
    string a,b;
    int aLen,bLen;
    while(l)
    {
        if(l%2==1) a='1'+a;
        else a='0'+a;
        l/=2;
    }
    aLen=a.size();
    while(r)
    {
        if(r%2==1) b='1'+b;
        else b='0'+b;
        r/=2;
    }
    bLen=b.size();
    string resA,resB;
    for(int i=0;i<n/aLen+1;i++) resA+=a;
    for(int i=0;i<n/bLen+1;i++) resB+=b;
    for(int i=0;i<n;i++)
    {
        if(resA[i]=='1' && resB[i]=='1') cout<<'1';
        else cout<<'0';
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}