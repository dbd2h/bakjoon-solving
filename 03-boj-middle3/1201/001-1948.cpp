#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void back(int *res, int cur, vector<int>(&parent)[10001],bool check[])
{
    if(parent[cur].size()==0) return;
    if(check[cur]) return;
    check[cur]=1;
    for(int i=0;i<parent[cur].size();i++)
    {
        (*res)++;
        back(res,parent[cur][i],parent,check);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[10001];
    int check[10001]={0};
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        check[b]++;
    }
    int start,end;
    cin>>start>>end;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(start);
    int time[10001]={0};
    vector<int> parent[10001];
    while(!pq.empty())
    {
        int cur=pq.top();
        pq.pop();
        int t=time[cur];
        for(int i=0;i<graph[cur].size();i++)
        {
            pair<int,int> p=graph[cur][i];
            int next=p.first;
            int w=p.second;
            check[next]--;
            if(check[next]==0) pq.push(next);
            if(time[next]<t+w)
            {
                parent[next].clear();
                time[next]=t+w;
                parent[next].push_back(cur);
            }
            else if(time[next]==t+w)
            {
                parent[next].push_back(cur);
            }
        }
    }
    cout<<time[end]<<"\n";
    int res=0;
    bool resCheck[10001]={0};
    back(&res,end,parent,resCheck);
    cout<<res;
}