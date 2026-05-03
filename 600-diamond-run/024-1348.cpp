#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define INF 1e9

using namespace std;

int graph[101][101]={0};

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool bfs(int lmatch[101], int rmatch[101], int dist[101], int n, int cCount, int pCount)
{
    queue<int> q;
    for(int i=1;i<=cCount;i++)
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
        for(int i=1;i<=pCount;i++)
        {
            if(graph[cur][i]==0 || graph[cur][i]>n) continue;
            int car=rmatch[i];
            if(car==0) found=true;
            else if(dist[car]==INF)
            {
                dist[car]=dist[cur]+1;
                q.push(car);
            }
        }
    }
    return found;
}

bool dfs(int lmatch[101], int rmatch[101], int dist[101], int n, int pCount, int cur)
{
    for(int i=1;i<=pCount;i++)
    {
        if(graph[cur][i]==0 || graph[cur][i]>n) continue;
        int car=rmatch[i];
        if(car==0 || (dist[car]==dist[cur]+1 && dfs(lmatch,rmatch,dist,n,pCount,car)))
        {
            lmatch[cur]=i;
            rmatch[i]=cur;
            return true;
        }
    }
    return false;
}

bool binaryMatching(int n, int cCount, int pCount)
{
    int lmatch[101]={0};
    int rmatch[101]={0};
    int dist[101];
    int res=0;
    while(bfs(lmatch,rmatch,dist,n,cCount,pCount))
    {
        for(int i=1;i<=cCount;i++)
        {
            if(lmatch[i]==0 && dfs(lmatch,rmatch,dist,n,pCount,i)) res++;
        }
    }
    return res==cCount;
}

int binarySearch(int l, int r, int cCount, int pCount)
{
    int middle=(l+r)/2;
    if(!binaryMatching(middle,cCount,pCount)) return binarySearch(middle+1,r,cCount,pCount);
    if(!binaryMatching(middle-1,cCount,pCount)) return middle;
    else return binarySearch(l,middle-1,cCount,pCount);
}

int main()
{
    int r,c;
    cin>>r>>c;
    int arr[50][50];
    vector<pair<int,int>> cv(101);
    int cCount=0;
    int pCount=0;
    for(int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<c;j++)
        {
            if(s[j]=='.') arr[i][j]=0;
            else if(s[j]=='X') arr[i][j]=-1;
            else if(s[j]=='C')
            {
                cCount++;
                arr[i][j]=0;
                cv[cCount]={i,j};
            }
            else if(s[j]=='P')
            {
                pCount++;
                arr[i][j]=pCount;
            }
        }
    }
    if(cCount==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=cCount;i++)
    {
        bool check[50][50]={0};
        queue<pair<pair<int,int>,int>> q;
        q.push({cv[i],0});
        check[cv[i].first][cv[i].second]=1;
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int w=q.front().second;
            if(arr[x][y]>0) graph[i][arr[x][y]]=w;
            q.pop();
            for(int j=0;j<4;j++)
            {
                int xp=x+cross[j][0];
                int yp=y+cross[j][1];
                if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
                if(check[xp][yp]) continue;
                if(arr[xp][yp]==-1) continue;
                q.push({{xp,yp},w+1});
                check[xp][yp]=1;
            }
        }
    }
    if(!binaryMatching(2500,cCount,pCount))
    {
        cout<<-1;
        return 0;
    }
    cout<<binarySearch(1,2500,cCount,pCount);
}