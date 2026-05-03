#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool isHospital[1001];
int graph[1001][1001][2];

int bfs(int n, int start, int t)
{
    int parent[1001];
    for(int i=1;i<=n;i++) parent[i]=-1;
    queue<pair<int,int>> q;
    bool check[1001]={0};
    q.push({start,0});
    check[start]=1;
    int h=-1;
    int time=1e9;
    while(!q.empty())
    {
        int cur=q.front().first;
        int curT=q.front().second;
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(graph[cur][i][0]==0) continue;
            if(check[i]) continue;
            if(curT+graph[cur][i][1]>t) continue;
            parent[i]=cur;
            check[i]=1;
            if(isHospital[i] && time>curT+graph[cur][i][1])
            {
                h=i;
                time=curT+graph[cur][i][1];
                continue;
            }
            q.push({i,curT+graph[cur][i][1]});
        }
    }
    if(h==-1) return -1;
    vector<int> flowV;
    while(h!=-1)
    {
        flowV.push_back(h);
        h=parent[h];
    }
    int len=flowV.size();
    int minV=1e9;
    for(int i=len-1;i>0;i--)
    {
        int a=flowV[i];
        int b=flowV[i-1];
        if(graph[a][b][0]<minV) minV=graph[a][b][0];
    }
    for(int i=len-1;i>0;i--)
    {
        int a=flowV[i];
        int b=flowV[i-1];
        graph[a][b][0]-=minV;
        graph[b][a][0]+=minV;
        graph[b][a][1]=-graph[a][b][1];
    }
    return (t-time+1)*minV;
}

void problem()
{
    int n;
    cin>>n;
    int start,p,s;
    cin>>start>>p>>s;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++) isHospital[i]=0;
    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        isHospital[num]=1;
    }
    int r;
    cin>>r;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graph[i][j][0]=0;
            graph[i][j][1]=0;
        }
    }
    for(int i=0;i<r;i++)
    {
        int a,b,people,t;
        cin>>a>>b>>people>>t;
        graph[a][b][0]=people;
        graph[a][b][1]=t;
    }
    int res=0;
    while(true)
    {
        int flow=bfs(n,start,s);
        if(flow==-1) break;
        res+=flow;
        if(res>=p)
        {
            res=p;
            break;
        }
    }
    cout<<res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}