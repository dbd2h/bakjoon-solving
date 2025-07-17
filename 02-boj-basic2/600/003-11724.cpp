#include <iostream>
#include <queue>

using namespace std;

void bfs(int (*graph)[1001], int *check, int n, int *cc);

int main()
{
    int n,m;
    cin>>n>>m;
    int check[n+1]={0};
    int graph[1001][1001]={0};
    int cc=0;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    bfs(graph, check, n, &cc);
    cout<<cc;
}

void bfs(int (*graph)[1001], int *check, int n, int *cc)
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==1)
        {
            continue;
        }
        q.push(i);
        check[i]=1;
        while(!q.empty())
        {
            int node=q.front();
            for(int j=1;j<=n;j++)
            {
                if(graph[node][j]==1&&check[j]==0)
                {
                    check[j]=1;
                    q.push(j);
                }
            }
            q.pop();
        }
        (*cc)++;
    }
}