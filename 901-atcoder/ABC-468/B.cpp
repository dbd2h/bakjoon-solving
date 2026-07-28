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

int main()
{
    int n,d;
    cin>>n>>d;
    string s;
    cin>>s;
    bool bit[100];
    for(int i=0;i<n;i++) bit[i]=1;
    int l=-200;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='G')
        {
            l=i;
            continue;
        }
        if(i-l<=d) bit[i]=0;
    }
    int r=300;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='G')
        {
            r=i;
            continue;
        }
        if(r-i<=d) bit[i]=0;
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='G') continue;
        res+=bit[i];
    }
    cout<<res;
}