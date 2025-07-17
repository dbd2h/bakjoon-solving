#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void dfs(int (*graph)[1001], int *check, stack<int> *s, int n, int node);

void bfs(int (*graph)[1001], int *check, queue<int> *q, int n, int node);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v;
    cin>>n>>m>>v;
    int graph[1001][1001]={0};
    int check[1001]={0};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    stack<int> s;
    queue<int> q;
    dfs(graph, check, &s, n, v);
    for(int i=1;i<=n;i++)
    {
        check[i]=0;
    }
    cout<<"\n";
    bfs(graph, check, &q, n, v);
}

void dfs(int (*graph)[1001], int *check, stack<int> *s, int n, int node)
{
    s->push(node);
    cout<<node<<" ";
    check[node]=1;
    for(int i=1;i<=n;i++)
    {
        if(graph[node][i]==1&&check[i]==0)
        {
            dfs(graph, check, s, n, i);
        }
    }
}

void bfs(int (*graph)[1001], int *check, queue<int> *q, int n, int node)
{
    q->push(node);
    check[node]=1;
    while(!(q->empty()))
    {
        int value=q->front();
        for(int i=1;i<=n;i++)
        {
            if(graph[value][i]==1&&check[i]==0)
            {
                q->push(i);
                check[i]=1;
            }
        }
        cout<<value<<" ";
        q->pop();
    }
    return;
}