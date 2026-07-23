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
vector<int> graph[LEN];
ll dp[LEN][2]={0};

void dfs(int cur, int p)
{
    int c=0;
    for(auto&next : graph[cur])
    {
        if(next==p) continue;
        c++;
        dfs(next,cur);
        c+=dp[next][1];
        dp[cur][0]+=dp[next][0];
    }
    dp[cur][0]+=c;
    dp[cur][1]=c;
}

void resMaker(int cur, int p, int n)
{
    if(p!=0)
    {
        dp[cur][0]=dp[p][0]+(n-2-dp[cur][1]*2);
    }
    for(auto&next : graph[cur])
    {
        if(next==p) continue;
        resMaker(next,cur,n);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0);
    resMaker(1,0,n);
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i][0]<<"\n";
    }
}