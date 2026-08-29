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
#define LEN 100001
#define MOD (ll)(998244353)

using namespace std;

ll inv[7];
ll arr[LEN][7];
ll rem[LEN];

int main()
{
    int n;
    cin>>n;
    priority_queue<pair<ll,int>> pq;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            cin>>arr[i][j];
            pq.push({arr[i][j],i});
        } 
        rem[i]=6;
    }
    for(int i=1;i<=6;i++)
    {
        ll cur=1;
        ll num=i;
        ll idx=MOD-2;
        while(idx)
        {
            if(idx%2==1)
            {
                cur*=num;
                cur%=MOD;
            } 
            num*=num;
            num%=MOD;
            idx/=2;
        }
        inv[i]=cur;
    }
    ll res=0;
    ll cur=1;
    while(!pq.empty())
    {
        ll num=pq.top().first;
        int idx=pq.top().second;
        pq.pop();
        ll sumV=cur*inv[rem[idx]];
        sumV%=MOD;
        sumV*=num;
        sumV%=MOD;
        res+=sumV;
        res%=MOD;
        cur*=inv[rem[idx]];
        cur%=MOD;
        cur*=rem[idx]-1;
        cur%=MOD;
        rem[idx]--;
    }
    cout<<res;
}