#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int graph[301][301]={0};
    for(int i=0;i<k;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(graph[a][b]==0 || graph[a][b]<c) graph[a][b]=c;
    }
    vector<pair<int,int>> graphV[301];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(graph[i][j]==0) continue;
            graphV[i].push_back({j,graph[i][j]});
        }
    }   
    int dp[301][301];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    dp[1][1]=0;
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dp[i][j]==-1) continue;
            int cur=dp[i][j];
            for(auto &next : graphV[j])
            {
                if(cur+next.second>dp[i+1][next.first]) dp[i+1][next.first]=cur+next.second;
            }
        }
    }
    int res=0;
    for(int i=2;i<=m;i++)
    {
        if(dp[i][n]>res) res=dp[i][n];
    }
    cout<<res;
}