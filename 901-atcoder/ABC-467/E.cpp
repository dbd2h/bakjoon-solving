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

int main()
{
    int n,m;
    cin>>n>>m;
    int A[LEN],B[LEN];
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n-1;i++) cin>>B[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    ll s=0;
    ll sumV=0;
    for(int i=0;i<n-1;i++)
    {
        ll cur=(A[i]+A[i+1]+s)%m;
        s=(B[i]-cur+m)%m;
        if(i%2==0)
        {
            pq.push({s+1,-1});
        }
        else
        {
            pq.push({m-s,1});
        }
        sumV+=s;
    }
    ll res=sumV;
    while(!pq.empty())
    {
        int c=pq.top().first;
        int a=pq.top().second;
        pq.pop();
        if(a==-1) sumV+=m;
        else sumV-=m;
        if(n%2==1)
        {
            res=min(res,sumV+c);
        }
        else res=min(res,sumV);
    }
    cout<<res;
}