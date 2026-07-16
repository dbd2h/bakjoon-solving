#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;

using namespace std;

int main()
{
    vector<pair<int,int>> v;
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    for(int i=c;i<=d;i++)
    {
        v.push_back({a*i,b*i});
    }
    vector<pair<int,int>> shelter;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        shelter.push_back({x,y});
    }
    int res=(1e9);
    for(int i=0;i<=d-c;i++)
    {
        for(int j=0;j<n;j++)
        {
            int len=0;
            len+=abs(v[i].first-shelter[j].first);
            len+=abs(v[i].second-shelter[j].second);
            res=min(res,len);
        }
    }
    cout<<res;
}