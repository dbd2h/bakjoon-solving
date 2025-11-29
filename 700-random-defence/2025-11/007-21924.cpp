#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    return p1.first<p2.first;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int parentArr[100001]={0};
    vector<pair<int,pair<int,int>>> v;
    long long tot=0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({c,{a,b}});
        tot+=(long long)c;
    }
    sort(v.begin(),v.end(),cmp);
    int len=v.size();
    long long res=0;
    int count=0;
    for(int i=0;i<len;i++)
    {
        int a=v[i].second.first;
        int b=v[i].second.second;
        int c=v[i].first;
        int pA=a;
        int pB=b;
        while(parentArr[pA])
        {
            pA=parentArr[pA];
        }
        while(parentArr[pB])
        {
            pB=parentArr[pB];
        }
        if(pA==pB) continue;
        else if(pA<pB)
        {
            pB=b;
            while(pB)
            {
                int bef=pB;
                pB=parentArr[pB];
                parentArr[bef]=pA;
            }
        }
        else if(pA>pB)
        {
            pA=a;
            while(pA)
            {
                int bef=pA;
                pA=parentArr[pA];
                parentArr[bef]=pB;
            }
        }
        res+=(long long) c;
        count++;
    }
    if(count!=n-1)
    {
        cout<<-1;
    }
    else cout<<tot-res;
}