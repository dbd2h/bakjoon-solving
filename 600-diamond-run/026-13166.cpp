#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define INF 1e9
#define LEN 200001

using namespace std;

vector<pair<int,int>> graph[LEN];

bool bfs(int lmatch[], int rmatch[], int dist[], int n, int len)
{
    queue<int> q;
    for(int i=1;i<=len;i++)
    {
        if(lmatch[i]==0)
        {
            q.push(i);
            dist[i]=0;
        }
        else dist[i]=INF;
    }

    bool found=false;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto& p : graph[cur])
        {
            if(p.second>n) continue;
            int c=rmatch[p.first];
            if(c==0) found=true;
            else if(dist[c]==INF)
            {
                dist[c]=dist[cur]+1;
                q.push(c);
            }
        }
    }
    return found;
}

bool dfs(int lmatch[], int rmatch[], int dist[], int n, int cur)
{
    for(auto& p : graph[cur])
    {
        if(p.second>n) continue;
        int c=rmatch[p.first];
        if(c==0 || (dist[c]==dist[cur]+1 && dfs(lmatch,rmatch,dist,n,c)))
        {
            lmatch[cur]=p.first;
            rmatch[p.first]=cur;
            return true;
        }
    }
    return false;
}

bool binaryMatching(int n, int len)
{
    int lmatch[LEN]={0};
    int rmatch[LEN*2]={0};
    int dist[LEN];
    int res=0;
    while(bfs(lmatch,rmatch,dist,n,len))
    {
        for(int i=1;i<=len;i++)
        {
            if(lmatch[i]==0 && dfs(lmatch,rmatch,dist,n,i)) res++;
        }
    }
    return res==len;
}

int binarySearch(int l, int r, int len)
{
    int middle=(l+r)/2;
    if(!binaryMatching(middle,len)) return binarySearch(middle+1,r,len);
    if(!binaryMatching(middle-1,len)) return middle;
    else return binarySearch(l,middle-1,len);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        graph[i].push_back({a,b});
        graph[i].push_back({c,d});
    }

    if(!binaryMatching(1000000,n))
    {
        cout<<-1;
        return 0;
    }
    cout<<binarySearch(0,1000000,n);
}