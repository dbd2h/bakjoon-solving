#include <iostream>
#include <queue>
#include <vector>

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
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    bool check[1001]={0};
    int res=0;
    while(true)
    {
        pair<int,int> p=pq.top();
        int w=p.first;
        int node=p.second;
        pq.pop();
        if(check[node]) continue;
        if(node==end)
        {
            res=w;
            break;
        }
        check[node]=1;
        for(int i=0;i<graph[node].size();i++)
        {
            pair<int,int> p1=graph[node][i];
            int next=p1.first;
            if(check[next]) continue;
            int w1=p1.second;
            pq.push({w+w1,next});
        }
    }
    cout<<res;
}