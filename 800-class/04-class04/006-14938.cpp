#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m,r;
    cin>>n>>m>>r;
    int arr[101];
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    vector<pair<int,int>> graph[101];
    for(int i=0;i<r;i++)
    {
        int a,b,l;
        cin>>a>>b>>l;
        graph[a].push_back({b,l});
        graph[b].push_back({a,l});
    }
    for(int i=1;i<=n;i++)
    {
        queue<pair<int,int>> q;
        q.push({i,0});
        int check[101];
        for(int j=1;j<=n;j++) check[j]=-1;
        check[i]=0;
        while(!q.empty())
        {
            int cur=q.front().first;
            int len=q.front().second;
            q.pop();
            if(check[cur]<len) continue;
            for(auto& nextP : graph[cur])
            {
                int nextLen=nextP.second+len;
                int next=nextP.first;
                if(nextLen>m) continue;
                if(check[next]!=-1 && check[next]<=nextLen) continue;
                check[next]=nextLen;
                q.push({next,nextLen});
            }
        }
        int curRes=0;
        for(int i=1;i<=n;i++)
        {
            if(check[i]==-1) continue;
            curRes+=arr[i];
        }
        if(res<curRes) res=curRes;
    }
    cout<<res;
}