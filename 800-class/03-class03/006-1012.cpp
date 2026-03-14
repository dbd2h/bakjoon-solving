#include <iostream>
#include <queue>

using namespace std;
int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void problem()
{
    int n,m,k;
    cin>>n>>m>>k;
    bool arr[50][50]={0};
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[x][y]=1;
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!arr[i][j]) continue;
            res++;
            queue<pair<int,int>> q;
            q.push({i,j});
            arr[i][j]=0;
            while(!q.empty())
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int xp=x+cross[j][0];
                    int yp=y+cross[j][1];
                    if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
                    if(arr[xp][yp]==0) continue;
                    q.push({xp,yp});
                    arr[xp][yp]=0;
                }
            }   
        }
    }
    cout<<res<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) problem();
}