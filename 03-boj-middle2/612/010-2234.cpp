#include <iostream>
#include <queue>

using namespace std;

int wall[50][50]={0};
int check[50][50]={0};
int cross[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int bit[2501]={0};

void bfs(int x, int y, int c)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y]=c;
    int rc=1;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        int w=wall[x][y];
        for(int i=0;i<4;i++)
        {
            int rem=w%2;
            w/=2;
            if(rem==1) continue;
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(check[xp][yp]!=0) continue;
            check[xp][yp]=c;
            q.push({xp,yp});
            rc++;
        }
    }
    bit[c]=rc;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>wall[i][j];
        }
    }
    int roomC=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(check[i][j]!=0) continue;
            roomC++;
            bfs(i,j,roomC);
            
        }
    }
    int maxV=0;
    cout<<roomC<<"\n";
    for(int i=1;i<=roomC;i++)
    {
        if(maxV<bit[i]) maxV=bit[i];
    }
    cout<<maxV<<"\n";
    int remV=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<4;k++)
            {
                int xp=i+cross[k][0];
                int yp=j+cross[k][1];
                if(xp<0 || xp>=m || yp<0 || yp>=n) continue;
                if(check[i][j]==check[xp][yp]) continue;
                if(bit[check[i][j]]+bit[check[xp][yp]]>remV) remV=bit[check[i][j]]+bit[check[xp][yp]];
            }
        }
    }
    cout<<remV;
}