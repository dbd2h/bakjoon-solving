#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

int cmp(pair<pair<ll,ll>,pair<ll,ll>> p1, pair<pair<ll,ll>,pair<ll,ll>> p2)
{
    return p1.second.second<p2.second.second;
}

void program()
{
    int n;
    cin>>n;
    vector<pair<pair<ll,ll>,pair<ll,ll>>> v;
    for(int i=0;i<n;i++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back({{a,b},{c,d}});
    }
    sort(v.begin(), v.end(), cmp);
    ll day=1;
    ll stat[3]={0};
    for(auto& p : v)
    {
        ll a=p.first.first;
        ll b=p.first.second;
        ll c=p.second.first;
        ll d=p.second.second;
        if(stat[0]<a)
        {
            day+=a-stat[0];
            stat[0]=a;
        }
        if(stat[1]<b)
        {
            day+=b-stat[1];
            stat[1]=b;
        }
        if(stat[2]<c)
        {
            day+=c-stat[2];
            stat[2]=c;
        }
        if(day>d)
        {
            cout<<"NO\n";
            return;
        }
        day++;
    }
    cout<<"YES\n";
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