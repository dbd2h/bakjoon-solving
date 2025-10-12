#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

void program()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int start=0;
    int end=0;
    int q=0;
    for(int i=0;i<k;i++)
    {
        int cur=s[i]-'0';
        if(cur==0)
        {
            start++;
        }
        else if(cur==1)
        {
            end++;
        }
        else if(cur==2)
        {
            q++;
        }
    }
    if(n==k)
    {
        for(int i=0;i<n;i++) cout<<'-';
        cout<<"\n";
        return;
    }
    for(int i=0;i<start;i++) cout<<'-';
    if(n-start-end<=q*2)
    {
        for(int i=0;i<n-start-end;i++) cout<<'?';
    }
    else
    {
        for(int i=0;i<q;i++) cout<<'?';
        for(int i=0;i<n-start-end-q*2;i++) cout<<'+';
        for(int i=0;i<q;i++) cout<<'?';
    }
    for(int i=0;i<end;i++) cout<<'-';
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}