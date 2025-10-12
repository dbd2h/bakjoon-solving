#include <iostream>
#include <vector>
#define LEN 100001

using namespace std;

void dfs(vector<int> (graph)[], int parent[][30], int level[], bool check[], int c, int cur)
{
    level[cur]=c;
    int idx=parent[cur][0];
    int nextI=0;
    while(parent[idx][nextI])
    {
        parent[cur][nextI+1]=parent[idx][nextI];
        idx=parent[idx][nextI];
        nextI++;
    }
    for(int next : graph[cur])
    {
        if(check[next]) continue;
        parent[next][0]=cur;
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
    vector<int> graph[LEN];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int parent[LEN][30]={0};
    int level[LEN];
    bool check[LEN]={0};
    parent[1][0]=0;
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
        int bit[20];
        if(levelA>levelB)
        {
            int c=0;
            int num=levelA-levelB;
            while(num)
            {
                if(num%2==1)
                {
                    a=parent[a][c];
                }
                num/=2;
                c++;
            }
        }
        else if(levelA<levelB)
        {
            int c=0;
            int num=levelB-levelA;
            while(num)
            {
                if(num%2==1)
                {
                    b=parent[b][c];
                }
                num/=2;
                c++;
            }
        }
        int c=0;
        while(parent[a][c])
        {
            c++;
        }
        c--;
        while(c>0)
        {
            if(parent[a][c]!=parent[b][c])
            {
                a=parent[a][c];
                b=parent[b][c];
            }
            c--;
        }
        while(a!=b)
        {
            a=parent[a][0];
            b=parent[b][0];
        }
        cout<<a<<"\n";
    }
}