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
#define LEN 200001

using namespace std;

ll arr[LEN];
vector<pair<ll,ll>> v;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll maxV=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    if(s[0]=='#') v.push_back({0,0});
    for(int l=1;l<=n;l++)
    {
        int r=l;
        while(true)
        {
            if(r>=n || s[l-1]!=s[r]) break;
            r++;
        }
        int c=0;
        ll maxNum=0;
        for(int i=l;i<=r;i++)
        {
            if(maxNum<arr[i])
            {
                maxNum=arr[i];
                c=1;
            }
            else if(maxNum==arr[i]) c++;
            if(l==1 && s[l-1]=='#') continue;
            if(r==n && s[r-1]=='#') continue;
            maxV=max(maxV,arr[i]);
        }
        l=r;
        v.push_back({maxNum,c});
    }
    if(s[n-1]=='#') v.push_back({0,0});
    int len=v.size();
    ll res=0;
    for(int i=1;i<len;i+=2)
    {
        if(v[i].first==maxV || v[i-1].first==maxV || v[i+1].first==maxV) res+=v[i-1].second*v[i+1].second;
    }
    cout<<res;
}