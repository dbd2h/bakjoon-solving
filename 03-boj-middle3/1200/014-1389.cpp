#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int graph[101][101]={0};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(j==k) continue;
                if(!graph[j][i] || !graph[i][k]) continue;
                if(graph[j][k]!=0 && graph[j][k]<=graph[j][i]+graph[i][k]) continue;
                graph[j][k]=graph[j][i]+graph[i][k];
            }
        }
    }
    int res=0;
    int sumV=-1;
    for(int i=1;i<=n;i++)
    {
        int s=0;
        for(int j=1;j<=n;j++)
        {
            s+=graph[i][j];
        }
        if(sumV==-1 || sumV>s)
        {
            res=i;
            sumV=s;
        }
    }
    cout<<res;
}