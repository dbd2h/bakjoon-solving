#include <iostream>

using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;
    int graph[401][401]={0};
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=c;
    
    }
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            for(int k=1;k<=v;k++)
            {
                if(graph[j][i]==0 || graph[i][k]==0) continue;
                if(graph[j][k]!=0 && graph[j][k]<=graph[j][i]+graph[i][k]) continue;
                if(graph[j][k]==0) graph[j][k]=graph[j][i]+graph[i][k];
                else graph[j][k]=min(graph[j][k],graph[j][i]+graph[i][k]);
            }
        }
    }
    int res=-1;
    for(int i=1;i<=v;i++)
    {
        if(graph[i][i]==0) continue;
        if(res==-1) res=graph[i][i];
        else res=min(res,graph[i][i]);
    }
    cout<<res;
}