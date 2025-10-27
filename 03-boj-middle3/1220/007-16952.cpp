#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int knight[8][2]={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int bishop[4][2]={{1,1},{-1,1},{1,-1},{-1,-1}};
int rook[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    int n;
    cin>>n;
    int arr[10][10];
    pair<int,int> start;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1) start={i,j};
        }
    }
    int check[10][10][101][3][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<=n*n;k++)
            {
                check[i][j][k][0][0]=-1;
                check[i][j][k][0][1]=-1;
                check[i][j][k][1][0]=-1;
                check[i][j][k][1][1]=-1;
                check[i][j][k][2][0]=-1;
                check[i][j][k][2][1]=-1;
            }
        }
    }
    check[start.first][start.second][1][0][0]=0;
    check[start.first][start.second][1][0][1]=0;
    check[start.first][start.second][1][1][0]=0;
    check[start.first][start.second][1][1][1]=0;
    check[start.first][start.second][1][2][0]=0;
    check[start.first][start.second][1][2][1]=0;
    queue<pair<pair<int,int>,pair<pair<int,int>,pair<int,int>>>> q;
    q.push({start,{{0,1},{0,0}}});
    q.push({start,{{0,1},{1,0}}});
    q.push({start,{{0,1},{2,0}}});
    int res=-1;
    int resC=-1;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second.first.first;
        int level=q.front().second.first.second;
        int cur=q.front().second.second.first;
        int change=q.front().second.second.second;
        q.pop();
        if(level==n*n)
        {
            if(res==-1)
            {
                res=c;
                resC=change;
            }
            else if(res>c)
            {
                res=c;
                resC=change;
            }
            else if(res==c && resC>change)
            {
                res=c;
                resC=change;
            }
            continue;
        }
        if(check[x][y][level][cur][0]<c || (check[x][y][level][cur][0]==c && check[x][y][level][cur][1]<change)) continue;
        for(int i=0;i<3;i++)
        {
            if(i==cur) continue;
            if(check[x][y][level][i][0]!=-1 && (check[x][y][level][i][0]<c+1 || (check[x][y][level][i][0]==(c+1) && check[x][y][level][i][1]<=change+1))) continue;
            check[x][y][level][i][0]=c+1;
            check[x][y][level][i][1]=change+1;
            q.push({{x,y},{{c+1,level},{i,change+1}}});
        }
        if(cur==0)
        {
            for(int i=0;i<8;i++)
            {
                int xp=x+knight[i][0];
                int yp=y+knight[i][1];
                if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                if(check[xp][yp][level][cur][0]!=-1 && (check[xp][yp][level][cur][0]<c+1 || (check[xp][yp][level][cur][0]==c+1 && check[xp][yp][level][cur][1]<=change))) continue;
                if(arr[xp][yp]==level+1)
                {
                    if(check[xp][yp][level+1][cur][0]!=-1 && (check[xp][yp][level+1][cur][0]<c+1 || (check[xp][yp][level+1][cur][0]==c+1 && check[xp][yp][level+1][cur][1]<=change))) continue;
                    check[xp][yp][level+1][cur][0]=c+1;
                    check[xp][yp][level+1][cur][1]=change;
                    q.push({{xp,yp},{{c+1,level+1},{cur,change}}});
                }
                else
                {
                    check[xp][yp][level][cur][0]=c+1;
                    check[xp][yp][level][cur][1]=change;
                    q.push({{xp,yp},{{c+1,level},{cur,change}}});
                }
            }
        }
        else if(cur==1)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<4;j++)
                {
                    int xp=x+bishop[j][0]*i;
                    int yp=y+bishop[j][1]*i;
                    if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                    if(check[xp][yp][level][cur][0]!=-1 && (check[xp][yp][level][cur][0]<c+1 || (check[xp][yp][level][cur][0]==c+1 && check[xp][yp][level][cur][1]<=change))) continue;
                    if(arr[xp][yp]==level+1)
                    {
                        if(check[xp][yp][level+1][cur][0]!=-1 && (check[xp][yp][level+1][cur][0]<c+1 || (check[xp][yp][level+1][cur][0]==c+1 && check[xp][yp][level+1][cur][1]<=change))) continue;
                        check[xp][yp][level+1][cur][0]=c+1;
                        check[xp][yp][level+1][cur][1]=change;
                        q.push({{xp,yp},{{c+1,level+1},{cur,change}}});
                    }
                    else
                    {
                        check[xp][yp][level][cur][0]=c+1;
                        check[xp][yp][level][cur][1]=change;
                        q.push({{xp,yp},{{c+1,level},{cur,change}}});
                    }
                }
            }
        }
        else if(cur==2)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<4;j++)
                {
                    int xp=x+rook[j][0]*i;
                    int yp=y+rook[j][1]*i;
                    if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                    if(check[xp][yp][level][cur][0]!=-1 && (check[xp][yp][level][cur][0]<c+1 || (check[xp][yp][level][cur][0]==c+1 && check[xp][yp][level][cur][1]<=change))) continue;
                    if(arr[xp][yp]==level+1)
                    {
                        if(check[xp][yp][level+1][cur][0]!=-1 && (check[xp][yp][level+1][cur][0]<c+1 || (check[xp][yp][level+1][cur][0]==c+1 && check[xp][yp][level+1][cur][1]<=change))) continue;
                        check[xp][yp][level+1][cur][0]=c+1;
                        check[xp][yp][level+1][cur][1]=change;
                        q.push({{xp,yp},{{c+1,level+1},{cur,change}}});
                    }
                    else
                    {
                        check[xp][yp][level][cur][0]=c+1;
                        check[xp][yp][level][cur][1]=change;
                        q.push({{xp,yp},{{c+1,level},{cur,change}}});
                    }
                }
            }
        }
    }
    cout<<res<<" "<<resC;
}