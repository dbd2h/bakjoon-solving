#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> graph[32001];
    int check[32001]={0};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        check[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1;i<=n;i++)
    {
        if(!check[i]) q.push(i);
    }
    while(!q.empty())
    {
        int num=q.top();
        q.pop();
        for(int i=0;i<graph[num].size();i++)
        {
            int next=graph[num][i];
            check[next]--;
            if(check[next]==0) q.push(next);
        }
        cout<<num<<" ";
    }
}