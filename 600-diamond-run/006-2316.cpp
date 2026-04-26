#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool graph[801][801]={0};

bool bfs(int n)
{
    bool check[801]={0};
    int parent[801]={0};
    queue<int> q;
    q.push(1);
    check[1]=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int i=1;i<=n*2-2;i++)
        {
            if(graph[cur][i]==0) continue;
            if(check[i]) continue;
            parent[i]=cur;
            q.push(i);
            check[i]=1;
            if(i==2) break;
        }
        if(parent[2]!=0) break;
    }
    if(parent[2]==0) return 0;
    vector<int> flowV;
    int idx=2;
    while(idx)
    {
        flowV.push_back(idx);
        idx=parent[idx];
    }
    int len=flowV.size();
    for(int i=len-1;i>0;i--)
    {
        graph[flowV[i]][flowV[i-1]]=0;
        graph[flowV[i-1]][flowV[i]]=1;
    }
    return 1;
}

int main()
{
    int n,p;
    cin>>n>>p;
    for(int i=3;i<=n;i++)
    {
        graph[i][n+i-2]=1;
    }
    for(int i=0;i<p;i++)
    {
        int a,b;
        cin>>a>>b;
        if(b==1 || a==2)
        {
            int c=a;
            a=b;
            b=c;
        }
        if(a==1)
        {
            graph[a][b]=1;
        }
        else if(b==2)
        {
            graph[a+n-2][b]=1;
        }
        else
        {
            graph[a+n-2][b]=1;
            graph[b+n-2][a]=1;
        }
    }
    int res=0;
    while(true)
    {
        int flow=bfs(n);
        if(!flow) break;
        res++;
    }
    cout<<res;
}