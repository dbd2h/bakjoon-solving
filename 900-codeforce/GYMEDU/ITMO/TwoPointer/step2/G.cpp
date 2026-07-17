#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 100001

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

struct MSTACK
{
    stack<ll> s,gcdS;
    void push(ll num)
    {
        s.push(num);
        if(gcdS.empty()) gcdS.push(num);
        else gcdS.push(gcd(gcdS.top(),num));
    }
    void pop()
    {
        s.pop();
        gcdS.pop();
    }

    ll gcdV(MSTACK &s2)
    {
        if(s.empty() && s2.s.empty()) return 2;
        else if(s.empty()) return s2.gcdS.top();
        else if(s2.s.empty()) return gcdS.top();
        else return gcd(gcdS.top(),s2.gcdS.top());
    }
};



ll arr[LEN];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    MSTACK st1,st2;
    int l=0;
    int r=0;
    int res=-1;
    while(r<=n)
    {
        if(st1.gcdV(st2)!=1)
        {
            r++;
            if(r>n) break;
            st2.push(arr[r]);
        }
        else
        {
            if(st1.s.empty())
            {
                while(!st2.s.empty())
                {
                    st1.push(st2.s.top());
                    st2.pop();
                }
            }
            if(res==-1 || res>(r-l)) res=(r-l);
            l++;
            st1.pop();
        }
    }
    cout<<res;
}