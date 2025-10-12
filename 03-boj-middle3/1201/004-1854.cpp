#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> graph[1001];
    priority_queue<ll> weight[1001];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    queue<pair<int,ll>> q;
    q.push({1,0});
    weight[1].push(0);
    while(!q.empty())
    {
        int cur=q.front().first;
        ll w=q.front().second;
        q.pop();
        for(int i=0;i<graph[cur].size();i++)
        {
            int next=graph[cur][i].first;
            int w1=graph[cur][i].second;
            if(weight[next].size()<k || weight[next].top()>(ll)w1 + w)
            {
                if(weight[next].size()==k) weight[next].pop();
                weight[next].push((ll)w1+w);
                q.push({next,(ll)w1+w});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(weight[i].size()<k) cout<<"-1\n";
        else cout<<weight[i].top()<<"\n";
    }
}