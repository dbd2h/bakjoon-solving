#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int time[10001]={0};
    vector<int> graph[10001];
    int check[10001]={0};
    for(int i=1;i<=n;i++)
    {
        int t,m;
        cin>>t>>m;
        time[i]=t;
        for(int j=0;j<m;j++)
        {
            int next;
            cin>>next;
            graph[i].push_back(next);
            check[next]++;
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==0) pq.push({time[i],i});
    }
    while(!pq.empty())
    {
        pair<int,int> t=pq.top();
        pq.pop();
        res=t.first;
        int cur=t.second;
        for(int i=0;i<graph[cur].size();i++)
        {
            int next=graph[cur][i];
            check[next]--;
            if(check[next]==0)
            {
                pq.push({res+time[next],next});
            }
        }
    }
    cout<<res;
}