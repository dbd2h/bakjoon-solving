#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int maze[102][102]={0};
    int check[102][102]={0};
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            maze[i][j+1]=s[j]-'0';
        }
    }
    queue<pair<int, int>> q;
    q.push({1,1});
    check[1][1]=1;
    while(!q.empty())
    {
        pair<int,int> a;
        a=q.front();
        q.pop();
        int r,c;
        r=a.first;
        c=a.second;
        for(int i=-1;i<=1;i+=2)
        {
            if(maze[r-i][c]==1&&check[r-i][c]==0)
            {
                q.push({r-i,c});
                check[r-i][c]=check[r][c]+1;
            }
            if(maze[r][c-i]==1&&check[r][c-i]==0)
            {
                q.push({r,c-i});
                check[r][c-i]=check[r][c]+1;
            }
        }
    }
    cout<<check[n][m];
}