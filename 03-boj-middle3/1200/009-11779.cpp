#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[1001];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    int start,end;
    cin>>start>>end;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{start,0}});
    bool check[1001]={0};
    int weight[1001]={0};
    int res=0;
    bool isF=false;
    int parentArr[1001]={0};
    while(!pq.empty())
    {
        pair<int,pair<int,int>> p=pq.top();
        pq.pop();
        int w=p.first;
        int node=p.second.first;
        int parent=p.second.second;
        if(check[node]) continue;
        check[node]=true;
        weight[node]=w;
        parentArr[node]=parent;
        if(end==node)
        {
            res=w;
            isF=true;
        }
        if(isF && w>res) break;
        for(int i=0;i<graph[node].size();i++)
        {
            pair<int,int> p1=graph[node][i];
            int next=p1.first;
            int w1=p1.second;
            if(check[next]) continue;
            pq.push({w+w1,{next,node}});
        }
    }
    vector<int> resV;
    int child=end;
    while(true)
    {
        if(child==0) break;
        resV.push_back(child);
        child=parentArr[child];
    }
    cout<<res<<"\n";
    cout<<resV.size()<<"\n";
    for(int i=resV.size()-1;i>=0;i--)
    {
        cout<<resV[i]<<" ";
    }
}