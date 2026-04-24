#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    vector<pair<int,int>> graph[1001];
    for(int i=0;i<m;i++)
    {
        int a,b,t;
        cin>>a>>b>>t;
        graph[a].push_back({b,t});
    }
    int resArr[1001];
    for(int i=1;i<=n;i++) resArr[i]=1e9;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,x});
    resArr[x]=0;
    while(!pq.empty())
    {
        int time=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(resArr[cur]<time) continue;
        for(auto &nextP : graph[cur])
        {
            if(resArr[nextP.first]<=time+nextP.second) continue;
            pq.push({time+nextP.second,nextP.first});
            resArr[nextP.first]=time+nextP.second;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(i==x) continue;
        int check[1001];
        for(int i=1;i<=n;i++) check[i]=1e9;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;
        pq1.push({0,i});
        check[i]=0;
        while(!pq1.empty())
        {
            int time=pq1.top().first;
            int cur=pq1.top().second;
            pq1.pop();
            if(check[cur]<time) continue;
            for(auto &nextP : graph[cur])
            {
                if(check[nextP.first]<=nextP.second+time) continue;
                pq1.push({nextP.second+time,nextP.first});
                check[nextP.first]=nextP.second+time;
            }
        }
        resArr[i]+=check[x];
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(resArr[i]>res) res=resArr[i];
    }
    cout<<res;
}