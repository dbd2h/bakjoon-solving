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
    string s;
    cin>>s;
    if(k*2>n)
    {
        cout<<-1<<"\n";
        return;
    }
    int res=0;
    for(int i=0;i<k;i++)
    {
        if(s[i]=='L') res++;
    }
    for(int i=n-k;i<n;i++)
    {
        if(s[i]=='R') res++;
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