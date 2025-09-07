#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int graph[101][101]={0};
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(!graph[a][b] || graph[a][b]>c) graph[a][b]=c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(!graph[j][i] || !graph[i][k]) continue;
                if(j==k) continue;
                if(!graph[j][k]) graph[j][k]=graph[j][i]+graph[i][k];
                else graph[j][k]=min(graph[j][k],graph[j][i]+graph[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}