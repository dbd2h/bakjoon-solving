#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first>p2.first;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);
    int day[10001]={0};
    day[0]=-1;
    int result=0;
    for(int i=0;i<n;i++)
    {
        int p,d;
        p=v[i].first;
        d=v[i].second;
        if(day[d]==-1) continue;
        result+=p;
        for(int j=d;j<=n;j++)
        {
            day[j]++;
            if(day[j]!=j) continue;
            for(int k=j;k>0;k--)
            {
                if(day[k]==-1) break;
                day[k]=-1;
            }
        }
    }
    cout<<result;
}