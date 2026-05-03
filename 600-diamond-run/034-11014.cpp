#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define LEN 6401
#define INF 1e9

using namespace std;

int lmatch[LEN];
int rmatch[LEN];
int dist[LEN];

bool bfs(vector<int> graph[LEN],int n)
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

bool dfs(vector<int> graph[LEN],int cur)
{
    for(auto& r : graph[cur])
    {
        int l=rmatch[r];
        if(l==0 || (dist[l]==dist[cur]+1 && dfs(graph,l)))
        {
            lmatch[cur]=r;
            rmatch[r]=cur;
            return true;
        }
    }
    dist[cur]=INF;
    return false;
}

int cross[6][2]={{1,1},{0,1},{-1,1},{1,-1},{0,-1},{-1,-1}};
void problem()
{
    int n,m;
    cin>>n>>m;
    int arr[80][80];
    int oddI=0;
    int evenI=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='x')
            {
                arr[i][j]=-1;
                continue;
            }
            if(j%2==0)
            {
                oddI++;
                arr[i][j]=oddI;
            }
            else
            {
                evenI++;
                arr[i][j]=evenI;
            }
        }
    }
    vector<int> graph[LEN];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j+=2)
        {
            int cur=arr[i][j];
            if(cur==-1) continue;
            for(int k=0;k<6;k++)
            {
                int xp=i+cross[k][0];
                int yp=j+cross[k][1];
                if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
                if(arr[xp][yp]==-1) continue;
                graph[cur].push_back(arr[xp][yp]);
            }
        }
    }
    
    for(int i=1;i<=oddI;i++)
    {
        lmatch[i]=0;
    }
    for(int i=1;i<=evenI;i++)
    {
        rmatch[i]=0;
    }
    int res=0;
    while(bfs(graph,oddI))
    {
        for(int i=1;i<=oddI;i++)
        {
            if(lmatch[i]==0 && dfs(graph,i)) res++;
        }
    }
    cout<<oddI+evenI-res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}