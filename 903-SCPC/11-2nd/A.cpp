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

int arr[LEN];
int dp[LEN][3];
int sumArr[LEN];

void program()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sumArr[0]=0;
    for(int i=1;i<=n;i++)
    {
        sumArr[i]=sumArr[i-1]+arr[i];
    }
    for(int i=1;i<n;i++)
    {
        sumArr[i]-=i;
    }
    ll tot=0;
    for(int i=1;i<n;i++) tot+=abs(sumArr[i]);
    if(sumArr[n]==n)
    {
        ll res=tot;
        cout<<res<<"\n";
        return;
    }
    else if(sumArr[n]==n+1)
    {
        ll res=tot;
        for(int i=n-1;i>=1;i--)
        {
            tot-=abs(sumArr[i]);
            tot+=abs(sumArr[i]-1);
            res=min(res,tot);
        }
        cout<<res<<"\n";
        return;
    }
    dp[n][0]=dp[n][1]=dp[n][2]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,n});
    for(int i=n-1;i>=1;i--)
    {
        dp[i][0]=dp[i+1][0];
        dp[i][1]=dp[i+1][1];
        dp[i][2]=dp[i+1][2];
        if(sumArr[i]>=2) dp[i][2]++;
        else if(sumArr[i]==1) dp[i][1]++;
        else dp[i][0]++;
        pq.push({dp[i][2]+dp[i][1]-dp[i][0],i});
    }
    ll res=(1e18);

    for(int i=n;i>=2;i--)
    {
        ll cur=tot;
        cur-=(dp[i][2]+dp[i][1]-dp[i][0]);
        while(!pq.empty() && pq.top().second>=i)
        {
            pq.pop();
        }
        int idx=pq.top().second;
        cur-=(dp[idx][2]+dp[idx][1]-dp[idx][0]-dp[i][1]*2);
        res=min(res,cur);
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