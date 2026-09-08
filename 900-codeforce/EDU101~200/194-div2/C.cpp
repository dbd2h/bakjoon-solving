#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;

using namespace std;

int bitArr[32]={0};

void program()
{
    ll x,y;
    cin>>x>>y;
    ll res=x+y;
    ll cur=0;
    ll bit=1;
    for(int i=0;i<32;i++) bitArr[i]=0;
    int idx=1;
    ll num=res;
    while(num)
    {
        if(num%2==1) bitArr[idx]=bit;
        idx++;
        num/=2;
        bit*=2;
    }
    idx--;
    while(idx)
    {
        if(cur+bitArr[idx]<=x) cur+=bitArr[idx];
        idx--;
    }
    cout<<res<<" "<<x-cur<<"\n";
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