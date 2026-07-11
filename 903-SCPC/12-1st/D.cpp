#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 200001
#define INF (ll)(1e18)

using namespace std;

ll weight[LEN];
vector<pair<pair<int,int>,pair<ll,ll>>> v;
ll arr[LEN][4];

int cmp(pair<pair<int,int>,pair<ll,ll>> p1, pair<pair<int,int>,pair<ll,ll>> p2)
{
    
    return p1.second.second<p2.second.second;
}

void program()
{
    int n,m;
    cin>>n>>m;
    v.clear();
    for(int i=1;i<=n;i++) weight[i]=INF;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i][0]=a;
        arr[i][1]=b;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i][2]=a;
        arr[i][3]=b;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        ll c,d;
        a=arr[i][0];
        b=arr[i][1];
        c=arr[i][2];
        d=arr[i][3];
        v.push_back({{a,b},{c,d}});
    }
    int startN,endN;
    cin>>startN>>endN;
    weight[startN]=0;
    sort(v.begin(),v.end(),cmp);
    int len=v.size();
    for(int i=0;i<len;i++)
    {
        int a=v[i].first.first;
        int b=v[i].first.second;
        ll w=v[i].second.first;
        if(weight[a]==INF && weight[b]==INF) continue;
        if(weight[a]+w<weight[b]) weight[b]=weight[a]+w;
        else if(weight[b]+w<weight[a]) weight[a]=weight[b]+w;
    }
    if(weight[endN]==INF) weight[endN]=-1;
    cout<<weight[endN]<<endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<endl;
        program();
    }
}