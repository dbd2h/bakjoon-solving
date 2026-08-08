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

void program()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int one=0;
    for(int i=0;i<n;i++)
    {
        one+=s[i]-'0';
    }
    int zero=n-one;
    if(zero+2<one || one+2<zero)
    {
        cout<<-1<<"\n";
        return;
    }
    int oneD=0;
    int zeroD=0;
    bool isOne=s[0]-'0';
    for(int i=1;i<n;i++)
    {
        bool cur=s[i]-'0';
        if(cur==isOne)
        {
            if(cur) oneD++;
            else zeroD++;
        }
        else
        {
            isOne=!isOne;
        }
    }
    if(oneD>zeroD)
    {
        cout<<oneD*2-1<<"\n";
    }
    else if(oneD<zeroD)
    {
        cout<<zeroD*2-1<<"\n";
    }
    else cout<<oneD*2<<"\n";
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