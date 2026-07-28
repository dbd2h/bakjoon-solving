#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
typedef long double lld;
#define LEN 300001

using namespace std;

ll arr[LEN];
ll sumArr[LEN];
vector<pair<ll,int>> v;
int befIdx[LEN];
int par[LEN];

int cmp(pair<ll,int> p1, pair<ll,int> p2)
{
    if(p1.first==p2.first) return p1.second>p2.second;
    return p1.first<p2.first;
}

int idxFind(int idx)
{
    if(idx==-1 || par[idx]==idx) return idx;
    par[idx]=idxFind(par[idx]);
    return par[idx];
}

void program()
{
    int n;
    ll m;
    v.clear();
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    ll sumV=0;
    for(int i=0;i<n;i++)
    {
        sumV+=arr[i];
        sumArr[i]=sumV;
        v.push_back({sumV,i});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        int curI=v[i].second;
        if(i==0) befIdx[curI]=-1;
        else befIdx[curI]=v[i-1].second;
        par[i]=i;
    }
    ll left=0;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        ll cur=m+left;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v[mid].first>cur) r=mid-1;
            else l=mid+1;
        }
        if(l>0)
        {
            int idx=v[l-1].second;
            idx=idxFind(idx);
            if(idx!=-1)
            {
                ll p=sumArr[idx]-left;
                res=max(res,p);
            }
        }
        par[i]=befIdx[i];
        left=sumArr[i];
    }
    cout<<res<<"\n";
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