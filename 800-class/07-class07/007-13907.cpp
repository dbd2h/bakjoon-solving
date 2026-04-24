#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int s,d;
    cin>>s>>d;
    int wArr[1001];
    int totW[1001];
    for(int i=0;i<=n;i++)
    {
        wArr[i]=1e9;
        totW[i]=1e9;
    } 
    vector<pair<int,int>> graph[1001];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{s,0},0});
    wArr[s]=0;
    while(!q.empty())
    {
        int cur=q.front().first.first;
        int c=q.front().first.second;
        int w=q.front().second;
        q.pop();
        if(cur==d)
        {
            if(totW[c]>w) totW[c]=w;
            continue;
        }
        for(auto &nextP : graph[cur])
        {
            int nextW=nextP.second+w;
            if(wArr[nextP.first]>nextW)
            {
                q.push({{nextP.first,c+1},nextW});
                wArr[nextP.first]=nextW;
            }
        }
    }
    for(int i=0;i<=k;i++)
    {
        int res=1e9;
        for(int j=0;j<=n;j++)
        {
            if(totW[j]<res) res=totW[j];
        }
        cout<<res<<"\n";
        if(i==k) break;
        int p;
        cin>>p;
        for(int j=1;j<=n;j++)
        {
            totW[j]+=(p*j);
        }
    }
}