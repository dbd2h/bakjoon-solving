#include <iostream>
#include <vector>

using namespace std;

void DAC(vector<int> &resV, int l, int r, int path[101][101])
{
    if(path[l][r]==r)
    {
        resV.push_back(r);
        return;
    }
    DAC(resV,l,path[l][r],path);
    DAC(resV,path[l][r],r,path);
}

int main()
{
    int n,m;
    cin>>n>>m;
    int graph[101][101]={0};
    int path[101][101]={0};
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(graph[a][b]!=0 && graph[a][b]<=c) continue;
        path[a][b]=b;
        graph[a][b]=c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(j==k) continue;
                if(!graph[j][i] || !graph[i][k]) continue;
                if(graph[j][k] && graph[j][k]<graph[j][i]+graph[i][k]) continue;
                graph[j][k]=graph[j][i]+graph[i][k];
                path[j][k]=i;
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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j]==0)
            {
                cout<<0<<"\n";
                continue;
            }
            vector<int> resV;
            resV.push_back(i);
            DAC(resV,i,j,path);
            cout<<resV.size()<<" ";
            for(int i=0;i<resV.size();i++)
            {
                cout<<resV[i]<<" ";
            }
            cout<<"\n";
        }
    }
}