#include <iostream>
#include <deque>

#define MAX_LEN 102

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int wall[MAX_LEN][MAX_LEN]={0};
    int count[MAX_LEN][MAX_LEN]={0};
    for(int i=0;i<MAX_LEN;i++)
    {
        for(int j=0;j<MAX_LEN;j++)
        {
            wall[i][j]=-1;
            count[i][j]=-1;
        }
    }
    char s[MAX_LEN];
    for(int i=0;i<m;i++)
    {
        cin>>s;
        for(int j=0;j<n;j++)
        {
            wall[i+1][j+1]=s[j]-'0';
        }
    }
    deque<pair<int,int>> dq;
    dq.push_back({1,1});
    count[1][1]=0;
    pair<int,int> cur;
    while(!dq.empty())
    {
        cur=dq.front();
        int x,y;
        x=cur.first;
        y=cur.second;
        if(x==m && y==n)
        {
            break;
        }
        dq.pop_front();
        if(wall[x+1][y]==0 && count[x+1][y]==-1)
        {
            dq.push_front({x+1,y});
            count[x+1][y]=count[x][y];
        }
        if(wall[x][y+1]==0 && count[x][y+1]==-1)
        {
            dq.push_front({x,y+1});
            count[x][y+1]=count[x][y];
        }
        if(wall[x-1][y]==0 && count[x-1][y]==-1)
        {
            dq.push_front({x-1,y});
            count[x-1][y]=count[x][y];
        }
        if(wall[x][y-1]==0 && count[x][y-1]==-1)
        {
            dq.push_front({x,y-1});
            count[x][y-1]=count[x][y];
        }
        if(wall[x+1][y]==1 && count[x+1][y]==-1)
        {
            dq.push_back({x+1,y});
            count[x+1][y]=count[x][y]+1;
        }
        if(wall[x][y+1]==1 && count[x][y+1]==-1)
        {
            dq.push_back({x,y+1});
            count[x][y+1]=count[x][y]+1;
        }
        if(wall[x-1][y]==1 && count[x-1][y]==-1)
        {
            dq.push_back({x-1,y});
            count[x-1][y]=count[x][y]+1;
        }
        if(wall[x][y-1]==1 && count[x][y-1]==-1)
        {
            dq.push_back({x,y-1});
            count[x][y-1]=count[x][y]+1;
        }
    }
    cout<<count[m][n];
}