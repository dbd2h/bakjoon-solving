#include <iostream>
#include <vector>

using namespace std;

void dfs(int level[], int parent[], int c, int cur, vector<int> (&graph)[], bool check[])
{
    level[cur]=c;
    for(int next : graph[cur])
    {
        if(check[next]) continue;
        check[next]=1;
        parent[next]=cur;
        dfs(level,parent,c+1,next,graph,check);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> graph[50001];
    int parent[50001];
    int level[50001];
    bool check[50001]={0};
    parent[1]=0;
    check[1]=1;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(level,parent,1,1,graph,check);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        int levelA=level[a];
        int levelB=level[b];
        while(levelA>levelB)
        {
            a=parent[a];
            levelA--;
        }
        while(levelA<levelB)
        {
            b=parent[b];
            levelB--;
        }
        while(a!=b)
        {
            a=parent[a];
            b=parent[b];
        }
        cout<<a<<"\n";
    }
}