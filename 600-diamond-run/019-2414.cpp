#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[2501];
int lmatch[2501]={0};
int rmatch[2501]={0};
int dist[2501];

bool bfs(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(lmatch[i]==0)
        {
            q.push(i);
            dist[i]=0;
        }
        else dist[i]=INF;
    }
    bool found=false;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto& col : graph[cur])
        {
            int row=rmatch[col];
            if(row==0) found=true;
            else if(dist[row]==INF)
            {
                q.push(row);
                dist[row]=dist[cur]+1;
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto& col : graph[cur])
    {
        int row=rmatch[col];
        if(row==0 || (dist[row]==dist[cur]+1 && dfs(row)))
        {
            lmatch[cur]=col;
            rmatch[col]=cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    bool arr[51][51];
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='.') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    int rowArr[51][51]={0};
    int colArr[51][51]={0};
    int idx=1;
    for(int i=1;i<=n;i++)
    {
        bool isInput=false;
        for(int j=1;j<=m;j++)
        {   
            if(arr[i][j]==1)
            {
                rowArr[i][j]=idx;
                isInput=true;
            } 
            else
            {
                isInput=false;
                if(j==1 || arr[i][j-1]==0) continue;
                else idx++;
            }
        }
        if(isInput) idx++;
    }
    idx=1;
    for(int i=1;i<=m;i++)
    {
        bool isInput=false;
        for(int j=1;j<=n;j++)
        {
            if(arr[j][i]==1)
            {
                colArr[j][i]=idx;
                isInput=true;
            } 
            else
            {
                isInput=false;
                if(j==1 || arr[j-1][i]==0) continue;
                else idx++;
            }
        }
        if(isInput) idx++;
    }
    int row=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j]==0) continue;
            graph[rowArr[i][j]].push_back(colArr[i][j]);
            if(rowArr[i][j]>row) row=rowArr[i][j];
        }
    }
    int res=0;
    while(bfs(row))
    {
        for(int i=1;i<=row;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    cout<<res;
}
