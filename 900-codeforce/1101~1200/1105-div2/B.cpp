#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define MOD (ll)998244353
#define LEN 1e9
#define pLEN 70

using namespace std;

ll powArr[pLEN];

ll resMaker(ll idx)
{
    ll res=1;
    int i=0;
    while(idx)
    {
        if(idx%2)
        {
            res*=powArr[i];
            res%=MOD;
        }
        i++;
        idx/=2;
    }
    return res;
}

void program()
{
    ll n,m,r,c;
    cin>>n>>m>>r>>c;
    ll res=1;
    res*=resMaker(r*c-1);
    res%=MOD;
    res*=resMaker((n-r)*(c-1));
    res%=MOD;
    res*=resMaker((m-c)*(r-1));
    res%=MOD;
    cout<<res<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    powArr[0]=2;
    for(int i=0;i<pLEN;i++) powArr[i+1]=powArr[i]*powArr[i]%MOD;
    for(int i=0;i<t;i++)
    {
        program();
    }
}

// 다시 풀기
