#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    bool graph[101][101]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>graph[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(graph[j][k]) continue;
                if(graph[j][i] && graph[i][k]) graph[j][k]=1;
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