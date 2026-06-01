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

using namespace std;

int cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first<p2.first;
}

void program()
{
    int n;
    cin>>n;
    int arr[LEN];
    
    int bit[LEN];
    vector<pair<int,int>> v;
    for(int i=0;i<=n;i++) bit[i]=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        bit[arr[i]]++;
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end(),cmp);
    ll res=0;
    for(int i=0;i<n;i++)
    {
        int h=v[i].first;
        int idx=v[i].second;
        res+=(ll)(i-idx)*h;
    }
    ll maxV=0;
    for(int i=n-1;i>=0;i--)
    {
        int cur=arr[i];
        int l=0;
        int r=i;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v[mid].first<cur) l=mid+1;
            else r=mid-1;
        }
        maxV=max(maxV,(ll)(i-(r+1)));
    }
    cout<<res+maxV<<"\n";
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