#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define LEN 10001

#define INF 1e9

using namespace std;

vector<int> graph[LEN];
int lmatch[LEN]={0};
int rmatch[LEN]={0};
int dist[LEN];

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
    return false;
}


int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main()
{
    int w,h;
    cin>>w>>h;
    vector<pair<int,int>> initB;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            int num;
            cin>>num;
            if(num==1)
            {
                initB.push_back({i,j});
            }
        }
    }
    int arr[100][100];
    int count=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)
            {
                count++;
                arr[i][j]=count;
            }
        }
    }
    if(count!=initB.size())
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<count;i++)
    {
        int x=initB[i].first;
        int y=initB[i].second;
        if(arr[x][y]!=0)
        {
            lmatch[i+1]=-1;
            rmatch[arr[x][y]]=-1;
            continue;
        }
        for(int j=0;j<4;j++)
        {
            int xp=x+cross[j][0];
            int yp=y+cross[j][1];
            if(xp<0 || xp>=h || yp<0 || yp>=w) continue;
            if(arr[xp][yp]==0) continue;
            if(rmatch[arr[xp][yp]]==-1) continue;
            graph[i+1].push_back(arr[xp][yp]);
        }
    }
    int res=0;
    while(bfs(count))
    {
        for(int i=1;i<=count;i++)
        {
            if(lmatch[i]==0 && dfs(i)) res++;
        }
    }
    for(int i=1;i<=count;i++)
    {
        if(lmatch[i]==0) res+=2;
    }
    cout<<res;
}