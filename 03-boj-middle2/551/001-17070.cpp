#include <iostream>

using namespace std;

int arr[16][16]={0};
long long c=0;

void dfs(int n, int x, int y, int sta) // sta = 1:가로, 2:세로, 3:대각선
{
    if(x==n-1 && y==n-1)
    {
        c++;
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(i==1 && sta==2) continue;
        if(i==2 && sta==1) continue;
        if(i==1)
        {
            if(y+1>=n || arr[x][y+1]==1) continue;
            dfs(n,x,y+1,i);
        }
        else if(i==2)
        {
            if(x+1>=n || arr[x+1][y]==1) continue;
            dfs(n,x+1,y,i);
        }
        else if(i==3)
        {
            if(x+1>=n || y+1>=n || arr[x+1][y]==1 || arr[x][y+1]==1 || arr[x+1][y+1]==1) continue;
            dfs(n,x+1,y+1,i);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    dfs(n,0,1,1);
    cout<<c;
}