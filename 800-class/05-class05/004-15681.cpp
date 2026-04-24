#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> graph[100001], int dp[], int cur, int p)
{
    dp[cur]=1;
    for(auto &next : graph[cur])
    {
        if(next==p) continue;
        dfs(graph,dp,next,cur);
        dp[cur]+=dp[next];
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,r,q;
    cin>>n>>r>>q;
    vector<int> graph[100001];
    int dp[100001]={0};
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(graph,dp,r,0);
    for(int i=0;i<q;i++)
    {
        int u;
        cin>>u;
        cout<<dp[u]<<"\n";
    }
}