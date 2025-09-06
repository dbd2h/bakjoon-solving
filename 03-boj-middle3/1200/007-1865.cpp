#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

void problem()
{
    ll n,m,w;
    cin>>n>>m>>w;
    vector<pair<pair<ll,ll>,ll>> edgeV;
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edgeV.push_back({{a,b},c});
        edgeV.push_back({{b,a},c});
    }
    for(ll i=0;i<w;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edgeV.push_back({{a,b},-c});
    }
    int check[501]={0};
    ll weight[501]={0};
    for(int t=1;t<=n;t++)
    {
        if(check[t]) continue;
        check[t]=t;
        for(ll i=0;i<n;i++)
        {
            bool isC=0;
            for(ll j=0;j<m*2+w;j++)
            {
                ll a,b,c;
                pair<pair<ll,ll>,ll> p=edgeV[j];
                a=p.first.first;
                b=p.first.second;
                c=p.second;
                if(check[a]!=t) continue;
                if(!check[b] || weight[a]+c<weight[b])
                {
                    weight[b]=weight[a]+c;
                    check[b]=t;
                    if(i==n-1)
                    {
                        cout<<"YES\n";
                        return;
                    }
                    isC=true;
                }
            }
            if(!isC) break;
        }
    }
    
    cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }
}