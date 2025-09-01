#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;

int ccw(pair<int,int> p1, pair<int,int> p2)
{
    ll res=0;
    res+=((ll) p1.first * (ll) p2.second);
    res-=((ll) p1.second * (ll) p2.first);
    if(res==0) return 0;
    else if(res<0) return 1;
    else return -1;
}

void DAC(vector<pair<int,int>> v, pair<int,int> sp, pair<int,int> fp, int *res)
{
    int vlen=v.size();
    if(vlen==0) return;
    (*res)++;
    ld maxV=0;
    int idx=-1;
    pair<int,int> pv1,pv2,cur,stp;
    for(int i=0;i<vlen;i++)
    {
        cur=v[i];
        if(cur==sp || cur==fp) continue;
        pair<int,int> pv1={fp.first-sp.first,fp.second-sp.second};
        pair<int,int> pv2={cur.first-sp.first,cur.second-sp.second};
        ld sin=((ld) pv1.first * (ld) pv2.second) - ((ld) pv1.second * (ld) pv2.first);
        sin=sin*sin;
        ld div=((ld) fp.first- (ld) sp.first)*((ld) fp.first- (ld) sp.first)+((ld) fp.second- (ld) sp.second)*((ld) fp.second- (ld) sp.second);
        div*= (((ld) cur.first- (ld) sp.first)*((ld) cur.first- (ld) sp.first)+((ld) cur.second- (ld) sp.second)*((ld) cur.second- (ld) sp.second));
        sin/=div;
        if(idx==-1 || maxV<sin)
        {
            idx=i;
            maxV=sin;
        }
    }
    stp=v[idx];
    pv1={stp.first-sp.first,stp.second-sp.second};
    vector<pair<int,int>> v1,v2;
    for(int i=0;i<vlen;i++)
    {
        cur=v[i];
        pv2={cur.first-sp.first,cur.second-sp.second};
        if(ccw(pv1,pv2)==1) v1.push_back(cur);
    }
    DAC(v1,sp,stp,res);
    pv1={fp.first-stp.first,fp.second-stp.second};
    for(int i=0;i<vlen;i++)
    {
        cur=v[i];
        pv2={cur.first-stp.first,cur.second-stp.second};
        if(ccw(pv1,pv2)==1) v2.push_back(cur);
    }
    DAC(v2,stp,fp,res);
}


int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    pair<int,int> p1,p2,p3,p4;
    p1={-40000,40000};
    p2={-40000,-40000};
    p3={40000,-40000};
    p4={40000,40000};
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        if(p1.second>b || p1.second==b && p1.first<a) p1={a,b};
        if(p2.first<a || p2.first==a && p2.second<b) p2={a,b};
        if(p3.second<b || p3.second==b && p3.first>a) p3={a,b};
        if(p4.first>a || p4.first==a && p4.second>b) p4={a,b};
    }
    int res=0;
    if(p1!=p2)
    {
        vector<pair<int,int>> v1;
        pair<int,int> sp,fp,pv1,pv2,cur;
        sp=p1;
        fp=p2;
        pv1={fp.first-sp.first,fp.second-sp.second};
        res++;
        for(int i=0;i<n;i++)
        {
            cur=v[i];
            pv2={cur.first-sp.first,cur.second-sp.second};
            if(ccw(pv1,pv2)==1) v1.push_back(cur);
        }
        DAC(v1,sp,fp,&res);
    }
    if(p2!=p3)
    {
        vector<pair<int,int>> v1;
        pair<int,int> sp,fp,pv1,pv2,cur;
        sp=p2;
        fp=p3;
        pv1={fp.first-sp.first,fp.second-sp.second};
        res++;
        for(int i=0;i<n;i++)
        {
            cur=v[i];
            pv2={cur.first-sp.first,cur.second-sp.second};
            if(ccw(pv1,pv2)==1) v1.push_back(cur);
        }
        DAC(v1,sp,fp,&res);
    }
    if(p3!=p4)
    {
        vector<pair<int,int>> v1;
        pair<int,int> sp,fp,pv1,pv2,cur;
        sp=p3;
        fp=p4;
        pv1={fp.first-sp.first,fp.second-sp.second};
        res++;
        for(int i=0;i<n;i++)
        {
            cur=v[i];
            pv2={cur.first-sp.first,cur.second-sp.second};
            if(ccw(pv1,pv2)==1) v1.push_back(cur);
        }
        DAC(v1,sp,fp,&res);
    }
    if(p4!=p1)
    {
        vector<pair<int,int>> v1;
        pair<int,int> sp,fp,pv1,pv2,cur;
        sp=p4;
        fp=p1;
        pv1={fp.first-sp.first,fp.second-sp.second};
        res++;
        for(int i=0;i<n;i++)
        {
            cur=v[i];
            pv2={cur.first-sp.first,cur.second-sp.second};
            if(ccw(pv1,pv2)==1) v1.push_back(cur);
        }
        DAC(v1,sp,fp,&res);
    }
    cout<<res;
}