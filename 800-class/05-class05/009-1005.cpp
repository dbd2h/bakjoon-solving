#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void problem()
{
    int n,k;
    cin>>n>>k;
    vector<int> graph[1001];
    int timeArr[1001];
    int befArr[1001]={0};
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        timeArr[i]=num;
    }
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        befArr[b]++;
    }
    int w;
    cin>>w;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=1;i<=n;i++)
    {
        if(befArr[i]!=0) continue;
        pq.push({timeArr[i],i});
    }
    while(!pq.empty())
    {
        int cur=pq.top().second;
        int time=pq.top().first;
        pq.pop();
        if(cur==w)
        {
            cout<<time<<"\n";
            return;
        }
        for(auto &next : graph[cur])
        {
            befArr[next]--;
            if(befArr[next]==0)
            {
                pq.push({time+timeArr[next],next});
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        problem();
    }
}