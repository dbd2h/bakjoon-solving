#include <iostream>
#include <queue>

using namespace std;

int board[20][20]={0};
int whereP[2][2]={0};
int cross[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void baduk(int n, int m, int c, int *maxN)
{
    if(c==1)
    {
        int board1[20][20]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board1[i][j]=board[i][j];
            }
        }
        board1[whereP[0][0]][whereP[0][1]]=1;
        board1[whereP[1][0]][whereP[1][1]]=1;
        int check[20][20]={0};
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!(board1[i][j]==2 && check[i][j]==0)) continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                check[i][j]=1;
                int count=1;
                int isSur=0;
                while(!q.empty())
                {
                    int x,y;
                    x=q.front().first;
                    y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int xp,yp;
                        xp=cross[k][0];
                        yp=cross[k][1];
                        if(x+xp<0 || x+xp>=n || y+yp<0 || y+yp>=m) continue;
                        if(check[x+xp][y+yp]) continue;
                        if(board1[x+xp][y+yp]==2)
                        {
                            check[x+xp][y+yp]=1;
                            q.push({x+xp,y+yp});
                            count++;
                        }
                        else if(board1[x+xp][y+yp]==0) isSur=1;
                    }
                }
                if(isSur==0)
                {
                    res+=count;
                }
            }
        }
        if(res>*maxN) *maxN=res;
        return;
    }
    for(int i=0;i<n*m;i++)
    {
        if(board[i/m][i%m]!=0) continue;
        whereP[0][0]=i/m;
        whereP[0][1]=i%m;
        for(int j=i+1;j<n*m;j++)
        {
            if(board[j/m][j%m]!=0) continue;
            int isCon=1;
            for(int a=0;a<4;a++)
            {
                int x=i/m;
                int y=i%m;
                int xp=cross[a][0];
                int yp=cross[a][1];
                if(x+xp<0 || x+xp>=n || y+yp<0 || y+yp>=m) continue;
                if(board[x+xp][y+yp]==2)
                {
                    isCon=0;
                    break;
                }
            }
            if(isCon)
            {
                for(int a=0;a<4;a++)
                {
                    int x=j/m;
                    int y=j%m;
                    int xp=cross[a][0];
                    int yp=cross[a][1];
                    if(x+xp<0 || x+xp>=n || y+yp<0 || y+yp>=m) continue;
                    if(board[x+xp][y+yp]==2)
                    {
                        isCon=0;
                        break;
                    }
                }
                if(isCon) continue;
            }
            whereP[1][0]=j/m;
            whereP[1][1]=j%m;
            baduk(n,m,1,maxN);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
    int res=0;
    baduk(n,m,0,&res);
    cout<<res;
}