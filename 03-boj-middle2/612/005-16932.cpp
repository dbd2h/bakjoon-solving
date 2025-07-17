#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[1000][1000]={0};

int cross[4][2]={{0,-1},{0,1},{1,0},{-1,0}};

void bfs(vector<int> &v, int n, int m, int x, int y, int c)
{
    arr[x][y]=c;
    queue<pair<int,int>> q;
    q.push({x,y});
    int count=1;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
            if(arr[xp][yp]!=1) continue;
            q.push({xp,yp});
            arr[xp][yp]=c;
            count++;
        }
    }
    v.push_back(count);
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
        }
    }
    vector<int> v;
    int c=2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                bfs(v,n,m,i,j,c);
                c++;
            }
        }
    }
    int maxV=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]!=0) continue;
            int s=1;
            int area[4]={0};
            for(int k=0;k<4;k++)
            {
                int isD=0;
                int xp=i+cross[k][0];
                int yp=j+cross[k][1];
                if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
                if(arr[xp][yp]==0) continue;
                for(int a=0;a<4;a++)
                {
                    if(arr[xp][yp]==area[a])
                    {
                        isD=1;
                        break;
                    }
                }
                if(isD) continue;
                s+=v[arr[xp][yp]-2];
                area[k]=arr[xp][yp];
            }
            if(maxV<s) maxV=s;
        }
    }
    cout<<maxV;
}