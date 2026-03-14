#include <iostream>
#include <queue>

using namespace std;

int cross[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

int main()
{
    int m,n,h;
    cin>>m>>n>>h;
    int tomato[100][100][100];
    queue<pair<pair<int,int>,pair<int,int>>> q;
    for(int k=0;k<h;k++)
    {
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                cin>>tomato[i][j][k];
                if(tomato[i][j][k]==1)
                {
                    q.push({{i,j},{k,0}});
                }
            }
        }
    }
    int res=0;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int z=q.front().second.first;
        int c=q.front().second.second;
        res=c;
        q.pop();
        for(int i=0;i<6;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            int zp=z+cross[i][2];
            if(xp<0 || xp>=m || yp<0 || yp>=n || zp<0 || zp>=h) continue;
            if(tomato[xp][yp][zp]!=0) continue;
            q.push({{xp,yp},{zp,c+1}});
            tomato[xp][yp][zp]=1;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<h;k++)
            {
                if(tomato[i][j][k]==0)
                {
                    res=-1;
                    break;
                }
            }
            if(res==-1) break;
        }
        if(res==-1) break;
    }
    cout<<res;
}