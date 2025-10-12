#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct cmp
{
    bool operator()(pair<pair<int,int>,pair<int,int>> p1, pair<pair<int,int>,pair<int,int>> p2)
    {
        if(p1.first.first==p2.first.first) return p1.second.first>p2.second.first;
        return p1.first.first>p2.first.first;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> 
    graph1[21];
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='.') continue;
            graph1[i].push_back({j+1,s[j]-'0'});
        }
    }
    vector<pair<int,int>> graph2[21];
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='.') continue;
            graph2[i].push_back({j+1,s[j]-'0'});
        }
    }
    priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>, cmp> pq;
    pq.push({{0,1},{0,0}});
    int w[21][2]={0};
    for(int i=2;i<=n;i++)
    {
        w[i][0]=1e8;
        w[i][1]=1e8;
    }
    while(!pq.empty())
    {
        int tot=pq.top().first.first;
        int cur=pq.top().first.second;
        int w1=pq.top().second.first;
        int w2=pq.top().second.second;
        pq.pop();
        if(w[cur][0]<w1 && w[cur][1]<w2) continue;
        for(int i=0;i<graph1[cur].size();i++)
        {
            int next=graph1[cur][i].first;
            int nextw1=w1+graph1[cur][i].second;
            int nextw2=w2+graph2[cur][i].second;
            if(w[next][0]<nextw1 && w[next][1]<nextw2) continue;
            pq.push({{nextw1*nextw2,next},{nextw1,nextw2}});
            if(w[next][0]*w[next][1]>nextw1*nextw2)
            {
                w[next][0]=nextw1;
                w[next][1]=nextw2;
            }
        }
    }
    if(w[2][0]==1e8) cout<<-1;
    else cout<<w[2][0]*w[2][1];
}
