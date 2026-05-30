#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(pair<long long, long long> p1,pair<long long, long long> p2)
{
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first<p2.first;
}

void problem()
{
    int n,k;
    cin>>n>>k;
    long long aArr[200000]={0};
    for(long long i=0;i<n;i++)
    {
        cin>>aArr[i];
    }
    vector<pair<long long,long long>> v;
    for(int i=0;i<n;i++)
    {
        long long num1=aArr[i];
        long long num2;
        cin>>num2;
        if(num1>num2)
        {
            int c=num1;
            num1=num2;
            num2=c;
        }
        v.push_back({num1,num2});
    }
    sort(v.begin(),v.end(),compare);
    int idx=-1;
    long long diff=-1;
    int diffI=-1;
    for(int i=1;i<n;i++)
    {
        if(v[i].first<v[i-1].second)
        {
            idx=i;
            break;
        }
        int d=v[i].first-v[i-1].second+v[i].second-v[i-1].first-(v[i].second-v[i].first+v[i-1].second-v[i-1].first);
        if(diff==-1 || diff>d)
        {
            diff=d;
            diffI=i;
        }
    }
    long long result=0;
    for(int i=0;i<n;i++)
    {
        result+=(v[i].second-v[i].first);
    }
    if(idx==-1)
    {
        result+=diff;
    }
    cout<<result<<"\n";
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