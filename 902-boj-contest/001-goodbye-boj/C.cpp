#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long ll;
typedef long double lld;

using namespace std;

int cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    return p1.first<p2.first;
}

int main()
{
    int n,d;
    cin>>n>>d;
    vector<pair<int,pair<int,int>>> v;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,{b,c}});
        if(b+c>res) res=b+c;
    }
    sort(v.begin(),v.end(),cmp);
    int idx=n;
    int maxA=0;
    int maxB=0;
    vector<pair<int,int>> maxV;
    for(int i=0;i<n;i++)
    {
        if(v[i].second.first>maxA) maxA=v[i].second.first;
        if(v[i].second.second>maxB) maxB=v[i].second.second;
        maxV.push_back({maxA,maxB});
    }
    idx=-1;
    for(int i=n-1;i>=0;i--)
    {
        int a=v[i].second.first;
        int b=v[i].second.second;
        int t=v[i].first;
        while(idx<n-1)
        {
            if(v[idx+1].first+t<=d)
            {
                idx++;
            }
            else break;
        }
        if(idx==-1) continue;
        if(maxV[idx].first+b>res) res=maxV[idx].first+b;
        if(maxV[idx].second+a>res) res=maxV[idx].second+a;
    }
    cout<<res;
}