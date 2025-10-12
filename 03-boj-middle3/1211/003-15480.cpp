#include <iostream>
#include <vector>
#include <stack>
#define LEN 100001

using namespace std;

void dfs(vector<int> (&graph)[], int parent[][20], int level[], int c, int cur)
{
    level[cur]=c;
    for(auto &next : graph[cur])
    {
        if(level[next]) continue;
        parent[next][0]=cur;
        int copyC=c;
        int copyCur=cur;
        int idx=1;
        while(copyC>1)
        {
            parent[next][idx]=parent[copyCur][idx-1];
            copyCur=parent[copyCur][idx-1];
            idx++;
            copyC/=2;
        }
        dfs(graph,parent,level,c+1,next);
    }
}

int lca(int parent[][20], int level[], int a, int b)
{
    if(level[a]<level[b])
    {
        int c=a;
        a=b;
        b=c;
    }
    int dis=level[a]-level[b];
    if(dis>0)
    {
        stack<int> st;
        while(dis)
        {
            st.push(dis%2);
            dis/=2;
        }
        while(!st.empty())
        {
            int s=st.size()-1;
            if(st.top()==1)
            {
                a=parent[a][s];
            }
            st.pop();
        }
    }
    if(a==b) return a;
    int idx=19;
    while(idx>=0)
    {
        if(parent[a][idx]) break;
        idx--;
    }
    while(idx>=0)
    {
        if(parent[a][idx]!=parent[b][idx])
        {
            a=parent[a][idx];
            b=parent[b][idx];
        }
        idx--;
    }
    while(a!=b)
    {
        a=parent[a][0];
        b=parent[b][0];
    }
    return a;
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
    int parent[LEN][20]={0};
    int level[LEN];
    dfs(graph,parent,level,1,1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int r,a,b;
        cin>>r>>a>>b;
        int lcaA=lca(parent,level,a,r);
        int lcaB=lca(parent,level,b,r);
        int lcaC=lca(parent,level,a,b);
        int res;
        if(level[lcaA]>level[lcaB])
        {
            if(level[lcaA]>level[lcaC]) res=lcaA;
            else res=lcaC;
        }
        else
        {
            if(level[lcaB]>level[lcaC]) res=lcaB;
            else res=lcaC;
        }
        cout<<res<<"\n";
    }
}