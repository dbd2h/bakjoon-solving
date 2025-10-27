#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int knight[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int bishop[4][2]={{1,1},{-1,1},{1,-1},{-1,-1}};
int rook[4][2]={{1,0},{-1,0},{0,1},{0,-1}};


int main()
{
    int n;
    cin>>n;
    int arr[10][10]={0};
    pair<int,int> start;
    int check[10][10][101][3]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)
            {
                start={i,j};
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;k<=n*n;k++)
            {
                check[i][j][k][0]=-1;
                check[i][j][k][1]=-1;
                check[i][j][k][2]=-1;
            }
        }
    }
    queue<pair<pair<int,int>,pair<pair<int,int>,int>>> q;
    check[start.first][start.second][1][0]=0;
    check[start.first][start.second][1][1]=0;
    check[start.first][start.second][1][2]=0;
    q.push({start,{{0,1},0}});
    q.push({start,{{0,1},1}});
    q.push({start,{{0,1},2}});
    int res=-1;
    while(!q.empty())// knight, bishop, rook
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second.first.first;
        int level=q.front().second.first.second;
        int cur=q.front().second.second;
        q.pop();
        if(level==n*n)
        {
            if(res==-1 || res>c) res=c;
            continue;
        }
        if(check[x][y][level][cur]<c) continue;
        for(int i=0;i<3;i++)
        {
            if(cur==i) continue;
            if(check[x][y][level][i]==-1 || check[x][y][level][i]>c+1)
            {
                q.push({{x,y},{{c+1,level},i}});
                check[x][y][level][i]=c+1;
            }
        }
        if(cur==0)
        {
            for(int i=0;i<8;i++)
            {
                int xp=x+knight[i][0];
                int yp=y+knight[i][1];
                if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                if(check[xp][yp][level][cur]!=-1 && check[xp][yp][level][cur]<=c+1) continue;
                if(arr[xp][yp]==level+1)
                {
                    if(check[xp][yp][level+1][cur]!=-1 && check[xp][yp][level+1][cur]<=c+1) continue;
                    q.push({{xp,yp},{{c+1,level+1},cur}});
                    check[xp][yp][level+1][cur]=c+1;
                }
                else
                {
                    q.push({{xp,yp},{{c+1,level},cur}});
                    check[xp][yp][level][cur]=c+1;
                }
            }
        }
        else if(cur==1)
        {
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<4;j++)
                {
                    int xp=x+bishop[j][0]*i;
                    int yp=y+bishop[j][1]*i;
                    if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                    if(check[xp][yp][level][cur]!=-1 && check[xp][yp][level][cur]<=c+1) continue;
                    if(arr[xp][yp]==level+1)
                    {
                        if(check[xp][yp][level+1][cur]!=-1 && check[xp][yp][level+1][cur]<=c+1) continue;
                        q.push({{xp,yp},{{c+1,level+1},cur}});
                        check[xp][yp][level+1][cur]=c+1;
                    }
                    else
                    {
                        q.push({{xp,yp},{{c+1,level},cur}});
                        check[xp][yp][level][cur]=c+1;
                    }
                }
            }
        }
        else if(cur==2)
        {
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<4;j++)
                {
                    int xp=x+rook[j][0]*i;
                    int yp=y+rook[j][1]*i;
                    if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                    if(check[xp][yp][level][cur]!=-1 && check[xp][yp][level][cur]<=c+1) continue;
                    if(arr[xp][yp]==level+1)
                    {
                        if(check[xp][yp][level+1][cur]!=-1 && check[xp][yp][level+1][cur]<=c+1) continue;
                        q.push({{xp,yp},{{c+1,level+1},cur}});
                        check[xp][yp][level+1][cur]=c+1;
                    }
                    else
                    {
                        q.push({{xp,yp},{{c+1,level},cur}});
                        check[xp][yp][level][cur]=c+1;
                    }
                }
            }
        }
    }
    cout<<res;
}   