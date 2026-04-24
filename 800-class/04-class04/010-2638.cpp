#include <iostream>
#include <queue>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int n,m;
    cin>>n>>m;
    bool cheese[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>cheese[i][j];
        }
    }
    int res=0;
    while(true)
    {
        queue<pair<int,int>> q;
        bool check[100][100]={0};
        q.push({0,0});
        check[0][0]=1;
        bool isF=true;
        int touch[100][100]={0};
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
                if(check[xp][yp]) continue;
                if(cheese[xp][yp])
                {
                    isF=false;
                    touch[xp][yp]++;
                } 
                else
                {
                    q.push({xp,yp});
                    check[xp][yp]=1;
                }
            }
        }
        if(isF) break;
        res++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(touch[i][j]>=2)
                {
                    cheese[i][j]=0;
                }
            }
        }
    }
    cout<<res;
    
}