#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[32002];


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int check[32001]={0};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        check[b]++;
    }
    queue<int> tsq;
    for(int i=1;i<=n;i++)
    {
        if(!check[i]) tsq.push(i);
    }
    while(!tsq.empty())
    {
        int cur=tsq.front();
        cout<<cur<<" ";
        tsq.pop();
        for(int i : graph[cur])
        {
            check[i]--;
            if(!check[i]) tsq.push(i);
        }
    }
}