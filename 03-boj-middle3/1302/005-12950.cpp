#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int dp[20][20]={0};
    queue<pair<int,int>> q;
    vector<pair<int,char>> graph[20];
    for(int i=0;i<m;i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        if(a>b)
        {
            int change=a;
            a=b;
            b=change;
        }
        dp[a][b]=1;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
        q.push({a,b});
    }
    for(int i=0;i<n;i++)
    {
        int len=graph[i].size();
        for(int j=0;j<len;j++)
        {
            for(int k=j+1;k<len;k++)
            {
                if(graph[i][j].second != graph[i][k].second) continue;
                int a=graph[i][j].first;
                int b=graph[i][k].first;
                if(a>b)
                {
                    int change=a;
                    a=b;
                    b=change;
                }
                if(dp[a][b]!=0) continue;
                dp[a][b]=2;
                q.push({a,b});
            }
        }
    }
    int res=-1;
    if(dp[0][1]!=0)
    {
        res=dp[0][1];
        cout<<res;
        return 0;
    }
    
    while(!q.empty())
    {
        int n1=q.front().first;
        int n2=q.front().second;
        q.pop();
        int c=dp[n1][n2];
        for(auto &next1 : graph[n1])
        {
            for(auto &next2 : graph[n2])
            {
                if(next1.second != next2.second) continue;
                int a=next1.first;
                int b=next2.first;
                if(a>b)
                {
                    int change=a;
                    a=b;
                    b=change;
                }
                if(dp[a][b]!=0) continue;
                dp[a][b]=c+2;
                q.push({a,b});
                if(a==0 && b==1)
                {
                    res=c+2;
                    break;
                }
            }
            if(res!=-1) break;
        }
        if(res!=-1) break;
    }
    cout<<res;
}