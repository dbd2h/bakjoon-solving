#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[52][52]={0};

int bfs()
{
    int parent[52];
    bool check[52]={0};
    for(int i=0;i<52;i++) parent[i]=-1;
    queue<int> q;
    q.push(0);
    check[0]=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int i=0;i<52;i++)
        {
            if(graph[cur][i]==0) continue;
            if(check[i]) continue;
            q.push(i);
            check[i]=1;
            parent[i]=cur;
            if(i==25) break;
        }
        if(parent[25]!=-1) break;
    }
    if(parent[25]==-1) return 0;
    vector<int> flowV;
    int idx=25;
    while(idx!=-1)
    {
        flowV.push_back(idx);
        idx=parent[idx];
    }
    int len=flowV.size();
    int minV=1e9;
    for(int i=len-1;i>0;i--)
    {
        int w=graph[flowV[i]][flowV[i-1]];
        if(minV>w) minV=w;
    }
    for(int i=len-1;i>0;i--)
    {
        graph[flowV[i]][flowV[i-1]]-=minV;
        graph[flowV[i-1]][flowV[i]]+=minV;
    }
    return minV;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        int aI;
        int bI;
        if(a-'A'>=0 && a-'A'<26) aI=a-'A';
        else aI=(a-'a')+26;
        if(b-'A'>=0 && b-'A'<26) bI=b-'A';
        else bI=(b-'a')+26;
        graph[aI][bI]+=c;
        graph[bI][aI]+=c;
    }
    int res=0;
    while(true)
    {
        int flow=bfs();
        if(flow==0) break;
        res+=flow;
    }
    cout<<res;
}