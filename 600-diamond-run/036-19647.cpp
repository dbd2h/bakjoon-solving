#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
#define LEN 1001

using namespace std;

vector<int> graph[1001];
int lmatch[1001]={0};
int rmatch[1001]={0};
int dist[1001];
bool leftN[1001]={0};
bool rightN[1001]={0};

bool bfs(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
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
        for(auto& r : graph[cur])
        {
            int l=rmatch[r];
            if(l==0) found=true;
            else if(dist[l]==INF)
            {
                q.push(l);
                dist[l]=dist[cur]+1;
            }
        }
    }
    return found;
}

bool dfs(int cur)
{
    for(auto& r : graph[cur])
    {
        int l=rmatch[r];
        if(l==0 || (dist[l]==dist[cur]+1 && dfs(l)))
        {
            lmatch[cur]=r;
            rmatch[r]=cur;
            return true;
        }
    }
    dist[cur]=INF;
    return false;
}

bool resF(int cur, int lN, int rN, bool check[])
{
    for(auto& r : graph[cur])
    {
        if(lN==cur && rN==r) continue;
        if(check[r]) continue;
        int l=rmatch[r];
        if(l==0)
        {
            return true;
        }
        else
        {
            check[r]=1;
            if(resF(l,lN,rN,check)) return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        for(int j=0;j<c;j++)
        {
            int ans;
            cin>>ans;
            graph[i].push_back(ans);
        }
    }
    int res=0;
    while(bfs(n))
    {
        for(int i=1;i<=n;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    if(n!=res)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        bool check[1001]={0};
        rmatch[lmatch[i]]=0;
        if(resF(i,i,lmatch[i],check)) 
        {
            cout<<-1;
            return 0;
        }
        rmatch[lmatch[i]]=i;
    }
    cout<<"1\n";
    for(int i=1;i<=n;i++)
    {
        cout<<lmatch[i]<<" ";
    }
}