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
#define INF (ll)(1e18)

using namespace std;

int main()
{
    ll n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        int cur=0;
        if(s[i]=='L') cur=1;
        else if(s[i]=='R') cur=2;
        if(!st.empty())
        {
            if(cur==0)
            {
                st.pop();
            }
            else st.push(cur);
            continue;
        }
        else if(cur==0)
        {
            x/=2;
        }
        else if(cur==1)
        {
            if(x*2>INF) st.push(1);
            else x*=2;
        }
        else if(cur==2)
        {
            if(x*2+1>INF) st.push(2);
            else x=x*2+1;
        }
    }
    cout<<x;
}