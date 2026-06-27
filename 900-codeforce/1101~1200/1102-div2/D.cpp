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
    int n,k;
    cin>>n>>k;
    string s1,s2;
    cin>>s1>>s2;
    int zero1=0;
    int zero2=0;
    int zero3=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]-'0'==0) zero1++;
        if(s2[i]-'0'==0) zero2++;
        if(s1[i]==s2[i]) zero3++;
    }
    ll bit[3][2];
    bit[0][0]=zero1;
    bit[0][1]=n-zero1;
    if(k%2==0)
    {
        bit[1][0]=zero2;
        bit[1][1]=n-zero2;
        bit[2][0]=zero3;
        bit[2][1]=n-zero3;
    }
    else
    {
        bit[1][0]=zero3;
        bit[1][1]=n-zero3;
        bit[2][0]=zero2;
        bit[2][1]=n-zero2;
    }
    ll res=0;
    for(int i=0;i<3;i++) res+=bit[i][0]*bit[i][1];
    ll c=1;
    while(k)
    {
        c*=2;
        k--;
    }
    c+=1;
    res*=(c/3);
    for(int i=0;i<c%3;i++)
    {
        res+=bit[i][0]*bit[i][1];
    }
    cout<<res<<"\n";
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