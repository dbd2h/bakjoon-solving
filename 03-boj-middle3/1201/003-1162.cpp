#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;


using namespace std;

struct compare
{
    bool operator()(pair<ll,pair<int,int>> p1, pair<ll,pair<int,int>> p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second.first<p2.second.first;
        }
        return p1.first>p2.first;
    }
};

int main()
{
    vector<pair<int,int>> graph[10001];
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>,compare> pq;
    bool check[10001][21]={0};
    pq.push({0,{k,1}});
    ll res=0;
    while(!pq.empty())
    {
        ll w=pq.top().first;
        int pack=pq.top().second.first;
        int cur=pq.top().second.second;
        pq.pop();
        if(check[cur][pack]) continue;
        if(n==cur)
        {
            res=w;
            break;
        }
        int c=pack;
        while(c>=0)
        {
            check[cur][c]=1;
            c--;
            if(check[cur][c]) break;
        }
        for(int i=0;i<graph[cur].size();i++)
        {
            int next=graph[cur][i].first;
            int w1=graph[cur][i].second;
            if(check[next][pack]) continue;
            pq.push({w+w1,{pack,next}});
            if(pack==0 || check[next][pack-1]) continue;
            pq.push({w,{pack-1,next}});
        }
    }
    cout<<res;
}