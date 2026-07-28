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

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void program()
{
    int n,k;
    cin>>n>>k;
    pq=priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>();
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        pq.push({num,i});
    }
    ll bef=pq.top().first;
    int l=pq.top().second;
    int r=pq.top().second;
    pq.pop();
    ll res=0;
    ll resC=0;
    while(!pq.empty() && bef<k)
    {
        if(bef==pq.top().first)
        {
            l=min(l,pq.top().second);
            r=max(r,pq.top().second);
            pq.pop();
            continue;
        }
        ll next=pq.top().first;
        next=min(next,(ll)k);
        res+=(next-bef);
        resC+=(next-bef)*(r-l+1);
        bef=next;
        l=min(l,pq.top().second);
        r=max(r,pq.top().second);
        pq.pop();
        if(bef>=k) break;
    }
    if(bef<k)
    {
        res+=(k-bef);
        resC+=(k-bef)*(r-l+1);
    }
    cout<<res<<" "<<resC<<"\n";
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