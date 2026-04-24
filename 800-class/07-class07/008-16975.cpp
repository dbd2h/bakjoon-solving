#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    ll arr[100001];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int m;
    cin>>m;
    vector<pair<pair<int,int>,ll>> v;
    int idx=0;
    for(int i=0;i<m;i++)
    {
        int d;
        cin>>d;
        if(d==1)
        {
            int a,b;
            ll c;
            cin>>a>>b>>c;
            v.push_back({{a,b},c});
            idx++;
            if(idx%1000==0)
            {
                int start=((idx-1)/1000)*1000;
                priority_queue<pair<int,ll>> pql;
                priority_queue<pair<int,ll>> pqr;
                for(int j=start;j<idx;j++)
                {
                    pql.push({-v[j].first.first,v[j].second});
                    pqr.push({-v[j].first.second,v[j].second});
                }
                ll sumV=0;
                for(int j=1;j<=n;j++)
                {
                    while(!pql.empty() && -pql.top().first==j)
                    {
                        sumV+= (ll) pql.top().second;
                        pql.pop();
                    }
                    while(!pqr.empty() && -pqr.top().first+1==j)
                    {
                        sumV-= (ll) pqr.top().second;
                        pqr.pop();
                    }
                    arr[j]+=sumV;
                }
            }
            
        }
        else if(d==2)
        {
            int x;
            cin>>x;
            int start=(idx/1000)*1000;
            ll res=arr[x];
            for(int j=start;j<idx;j++)
            {
                if(!(v[j].first.first<=x && v[j].first.second>=x)) continue;
                res+=(ll)v[j].second;
            }
            cout<<res<<"\n";
        }
    }
}