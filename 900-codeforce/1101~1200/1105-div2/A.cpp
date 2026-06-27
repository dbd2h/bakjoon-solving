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

ll powArr[22];


void program()
{
    ll res=0;
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        ll cur=n/(k-i+1);
        for(int j=0;j<21;j++)
        {
            if((powArr[j]-1)<=cur && (powArr[j+1]-2)>=cur)
            {
                n-=(powArr[j]-1);
                res+=(ll)j;
                break;
            }
        }
    }   
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    powArr[0]=1;
    for(int i=0;i<21;i++) powArr[i+1]=powArr[i]*2;
    for(int i=0;i<t;i++)
    {
        program();
    }
}

// 다시 풀기