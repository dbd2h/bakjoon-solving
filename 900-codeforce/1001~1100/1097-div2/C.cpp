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
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int count=0;
    bool isNo=false;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(a[i]==')' || b[i]==')')
            {
                isNo=true;
                break;
            }
        }
        else if(i==n-1)
        {
            if(a[i]=='(' || b[i]=='(')
            {
                isNo=true;
                break;
            }
        }
        if(a[i]=='(') count++;
        else count--;
        if(b[i]=='(') count++;
        else count--;
        if(count<0 || (i%2==0 && count==0)) isNo=true;
    }
    if(count!=0) isNo=true;
    if(isNo) cout<<"NO\n";
    else cout<<"YES\n";
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