#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

#define LEN 300001

using namespace std;

void program()
{
    string s;
    cin>>s;
    int dp[LEN];
    int res=0;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='4') res++;
    }
    int odd=0;
    int even=0;
    for(int i=0;i<len;i++)
    {
        int cur=s[i]-'0';
        if(cur==4) continue;
        else if(cur==2)
        {
            even++;
            if(odd<=even)
            {
                res+=odd;
                odd=0;
                even=0;
            }
        }
        else odd++;
    }
    res+=even;
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