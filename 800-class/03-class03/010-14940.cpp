#include <iostream>
#include <queue>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int arr[1000][1000];
    int check[1000][1000];
    int n,m;
    cin>>n>>m;
    pair<int,int> start;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            check[i][j]=-1;
            if(arr[i][j]==0) check[i][j]=0;
            else if(arr[i][j]==2) start={i,j};
        }
    }
    queue<pair<int,int>> q;
    q.push(start);
    check[start.first][start.second]=0;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
            if(check[xp][yp]!=-1) continue;
            check[xp][yp]=check[x][y]+1;
            q.push({xp,yp});
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<check[i][j]<<" ";
        }
        cout<<"\n";
    }
}