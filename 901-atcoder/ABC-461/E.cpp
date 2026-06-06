#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#define LEN 30001
typedef long long ll;

using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int rArr[LEN]={0};
    int cArr[LEN]={0};
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            rArr[b]=i;
        }
        else
        {
            cArr[b]=i;
        }
    }
    vector<int> colV;
    for(int i=1;i<=n;i++)
    {
        if(cArr[i]==0) continue;
        colV.push_back(cArr[i]);
    }
    sort(colV.begin(),colV.end());
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(rArr[i]==0) continue;
        int l=0;
        int r=colV.size()-1;
        ll cur=rArr[i];
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(colV[mid]>cur) r=mid-1;
            else l=mid+1;
        }
        res+=cur;
        res-=(ll)(colV.size()-l);
    }
    cout<<res;
}