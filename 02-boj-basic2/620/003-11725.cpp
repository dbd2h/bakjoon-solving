#include <iostream>
#include <vector>
#include <queue>

#define MAX_LEN 100'001

using namespace std;

int main()
{
    int n;
    int visit[MAX_LEN]={0};
    int parent[MAX_LEN]={0};
    vector<int> v[MAX_LEN];
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,w;
        cin>>u>>w;
        v[u].push_back(w);
        v[w].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visit[1]=1;
    int cur;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        for (int i : v[cur])
        {
            if(visit[i]==1)
            {
                continue;
            }
            visit[i]=1;
            parent[i]=cur;
            q.push(i);
        }
    }
    for(int i=2;i<=n;i++)
    {
        cout<<parent[i]<<"\n";
    }
}