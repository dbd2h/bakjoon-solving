#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void dfs(vector<pair<int,int>> (graph)[], int parent[][20][3], int level[], int c, int cur)
{
    level[cur]=c;
    for(auto &next : graph[cur])
    {
        if(level[next.first]) continue;
        parent[next.first][0][0]=cur;
        parent[next.first][0][1]=next.second;
        parent[next.first][0][2]=next.second;
        int copyC=c;
        int idx=1;
        int curC=cur;
        while(copyC>1)
        {
            parent[next.first][idx][0]=parent[curC][idx-1][0];
            parent[next.first][idx][1]=min(parent[curC][idx-1][1], parent[next.first][idx-1][1]);
            parent[next.first][idx][2]=max(parent[curC][idx-1][2], parent[next.first][idx-1][2]);
            curC=parent[next.first][idx][0];
            idx++;
            copyC/=2;
        }
        dfs(graph,parent,level,c+1,next.first);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> graph[100001];
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int parent[100001][20][3];
    int level[100001]={0};
    dfs(graph,parent,level,1,1);
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        int levelA=level[a];
        int levelB=level[b];
        int minL=10000000;
        int maxL=0;
        if(levelA>levelB)
        {
            int dis=levelA-levelB;
            stack<bool> st;
            while(dis)
            {
                st.push(dis%2);
                dis/=2;
            }
            while(!st.empty())
            {
                int s=st.size()-1;
                int cur=st.top();
                st.pop();
                if(cur==0) continue;
                if(minL>parent[a][s][1]) minL=parent[a][s][1];
                if(maxL<parent[a][s][2]) maxL=parent[a][s][2];
                a=parent[a][s][0];
            }
            levelA=levelB;
        }
        else if(levelA<levelB)
        {
            int dis=levelB-levelA;
            stack<bool> st;
            while(dis)
            {
                st.push(dis%2);
                dis/=2;
            }
            while(!st.empty())
            {
                int s=st.size()-1;
                int cur=st.top();
                st.pop();
                if(cur==0) continue;
                if(minL>parent[b][s][1]) minL=parent[b][s][1];
                if(maxL<parent[b][s][2]) maxL=parent[b][s][2];
                b=parent[b][s][0];
            }
            levelB=levelA;
        }
        int idx=19;
        while(idx>=0 && parent[a][idx][0]==0)
        {
            idx--;
        }
        while(idx>=0)
        {
            if(parent[a][idx][0]==parent[b][idx][0])
            {
                idx--;
                continue;
            }
            if(minL>parent[a][idx][1]) minL=parent[a][idx][1];
            if(maxL<parent[a][idx][2]) maxL=parent[a][idx][2];
            if(minL>parent[b][idx][1]) minL=parent[b][idx][1];
            if(maxL<parent[b][idx][2]) maxL=parent[b][idx][2];
            a=parent[a][idx][0];
            b=parent[b][idx][0];
            idx--;
        }
        while(a!=b)
        {
            if(minL>parent[a][0][1]) minL=parent[a][0][1];
            if(maxL<parent[a][0][2]) maxL=parent[a][0][2];
            if(minL>parent[b][0][1]) minL=parent[b][0][1];
            if(maxL<parent[b][0][2]) maxL=parent[b][0][2];
            a=parent[a][0][0];
            b=parent[b][0][0];
        }
        cout<<minL<<" "<<maxL<<"\n";
    }
}