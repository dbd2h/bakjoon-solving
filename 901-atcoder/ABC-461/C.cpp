#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;

using namespace std;

int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    priority_queue<pair<ll,ll>> pq;
    bool check[200001]={0};
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        pq.push({b,a});
    }
    ll res=0;
    while(!pq.empty() && k)
    {
        ll w=pq.top().first;
        ll idx=pq.top().second;
        pq.pop();
        if(check[idx] && k==m) continue;
        else if(check[idx]==0) m--;
        check[idx]=1;
        k--;
        res+=w;
    }
    cout<<res;
}