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
    string s;
    cin>>n>>k>>s;
    string res;
    int idx=-1;
    int sumV=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i]==')')
        {
            if(sumV>0) sumV--;
            else idx=i;
        }
        else sumV++;
    }
    for(int i=0;i<=idx;i++)
    {
        if(s[i]==')' || k==0)
        {
            res+='0';
            continue;
        }
        k--;
        res+='1';
    }
    for(int i=idx+1;i<n;i++)
    {
        if(s[i]=='(' || k==0) 
        {
            res+='0';
            continue;
        }
        k--;
        res+='1';
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