#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<pair<int,int>> (&graph)[], int parent[][2], int level[], bool check[], int c, int cur)
{
    level[cur]=c;
    for(auto &p : graph[cur])
    {
        int next=p.first;
        int w=p.second;
        if(check[next]) continue;
        parent[next][0]=cur;
        parent[next][1]=w;
        check[next]=1;
        dfs(graph,parent,level,check,c+1,next);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> graph[40001];
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int parent[40001][2];
    int level[40001];
    parent[1][0]=0;
    parent[1][1]=0;
    bool check[40001]={0};
    check[1]=1;
    dfs(graph,parent,level,check,1,1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        int levelA=level[a];
        int levelB=level[b];
        int res=0;
        while(levelA>levelB)
        {
            res+=parent[a][1];
            a=parent[a][0];
            levelA--;
        }
        while(levelA<levelB)
        {
            res+=parent[b][1];
            b=parent[b][0];
            levelB--;
        }
        while(a!=b)
        {
            res+=parent[a][1];
            res+=parent[b][1];
            a=parent[a][0];
            b=parent[b][0];
        }
        cout<<res<<"\n";
    }
}