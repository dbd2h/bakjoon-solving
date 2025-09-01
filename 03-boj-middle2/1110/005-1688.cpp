#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int isCrossed(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3, pair<ll,ll> p4) // p1:standing point , p2:(-1,-1), p3,p4:ordered point
{
    if(p1.first==p3.first && p1.second == p3.second) return 2;
    if(p1.first==p4.first && p1.second == p4.second) return 2;
    ll x1=p2.first-p1.first;
    ll y1=p2.second-p1.second;
    ll x2=p3.first-p1.first;
    ll y2=p3.second-p1.second;
    ll x3=p4.first-p1.first;
    ll y3=p4.second-p1.second;
    ll x4=p4.first-p3.first;
    ll y4=p4.second-p3.second;
    ll x5=p1.first-p3.first;
    ll y5=p1.second-p3.second;
    ll x6=p2.first-p3.first;
    ll y6=p2.second-p3.second;

    ll ccw1=x1*y2-x2*y1;
    ll ccw2=x1*y3-x3*y1;
    ll ccw3=x4*y5-x5*y4;
    ll ccw4=x4*y6-x6*y4;

    if((ccw1!=0 && ccw2!=0 && ccw3!=0 && ccw4!=0) && (ccw1^ccw2)<0 && (ccw3^ccw4)<0) return 1;
    pair<ll,ll> pl, ph;
    pl=p3;
    ph=p4;
    if(p3.first==p4.first) //y
    {
        if(p3.second>p4.second)
        {
            pl=p4;
            ph=p3;
        }
    }
    //x
    
    if(p3.first>p4.first)
    {
        pl=p4;
        ph=p3;
    }
    if(ccw3==0)
    {
        if(p3.first==p4.first) //y
        {
            if(pl.second<p1.second && ph.second>p1.second) return 2;
        }
        //x
        else if(pl.first<p1.first && ph.first>p1.first) return 2;
    }
    if(ccw1==0 && ccw2==0 && ccw3==0 && ccw4==0)
    {
        if(p3.first==p4.first)
        {
            if(ph.second<p1.second) return 1;
            else return 0;
        }
        if(ph.first<p1.first) return 1;
        else return 0;
    }
    
    if(ccw2==0)
    {
        if(p1.first>p4.first && p2.first<p4.first) return 1;
        else return 0;
    }
    return 0;

}

int main()
{
    int n;
    cin>>n;
    vector<pair<ll,ll>> v;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    pair<ll,ll> start={-1,-1};
    for(int i=0;i<3;i++)
    {
        ll x,y;
        cin>>x>>y;
        pair<ll,ll> p={x,y};
        int cnt=0;
        bool isF=0;
        for(int j=0;j<n;j++)
        {
            pair<ll,ll> p1,p2;
            p1=v[j];
            p2=v[(j+1)%n];
            int funcV=isCrossed(p,start,p1,p2);
            if(funcV==1) cnt++;
            else if(funcV==2)
            {
                isF=1;
                break;
            }
        }
        if(isF || cnt%2==1) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}