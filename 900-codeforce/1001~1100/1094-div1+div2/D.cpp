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

void program()
{
    int n;
    cin>>n;
    vector<pair<ll,int>> v(n);
    v[0].first=0;
    v[0].second=0;
    for(int i=1;i<=n;i++)
    {
        ll num;
        cin>>num;
        if(i==n) break;
        v[i].first=num+v[i-1].first;
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    vector<int> resV(n);
    for(int i=0;i<n;i++)
    {
        resV[v[i].second]=n-i;
    }
    for(int i=0;i<n;i++) cout<<resV[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        program();
    }
}