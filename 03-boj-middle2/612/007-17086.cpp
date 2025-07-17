#include <iostream>
#include <queue>

using namespace std;

int arr[50][50]={0};
int safe[50][50]={0};

int cross[8][2]={{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{0,1},{-1,0},{0,-1}};

void bfs(int n, int m, int x, int y)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},1});
    while(!q.empty())
    {
        x=q.front().first.first;
        y=q.front().first.second;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp >=n || yp<0 || yp>=m) continue;
            if(safe[xp][yp]!=0 && safe[xp][yp]<=c+1) continue;
            safe[xp][yp]=c+1;
            q.push({{xp,yp},c+1});
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
            cin>>arr[i][j];
            if(arr[i][j]==1)
            {
                safe[i][j]=1;
                bfs(n,m,i,j);
            }
        }
    }
    int maxV=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0 && safe[i][j]>maxV) maxV=safe[i][j];
        }
    }
    cout<<maxV-1;
}