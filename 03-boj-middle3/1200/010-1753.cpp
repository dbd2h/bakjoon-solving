#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int v,e,k;
    cin>>v>>e>>k;
    vector<pair<int,int>> graph[20001];
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    bool check[20001]={0};
    int weight[20001]={0};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,k});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        int w=p.first;
        int node=p.second;
        if(check[node]) continue;
        check[node]=1;
        weight[node]=w;
        for(int i=0;i<graph[node].size();i++)
        {
            pair<int,int> p1=graph[node][i];
            int next=p1.first;
            int w1=p1.second;
            if(check[next]) continue;
            pq.push({w+w1,next});
        }
    }
    for(int i=1;i<=v;i++)
    {
        if(check[i]==0)
        {
            cout<<"INF\n";
        }
        else
        {
            cout<<weight[i]<<"\n";
        }
    }
}