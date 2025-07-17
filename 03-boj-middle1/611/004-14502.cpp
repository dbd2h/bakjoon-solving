#include <iostream>
#include <queue>

using namespace std;

int lab[8][8]={0};
int wallMake[3][2]={0};
int maxSpace=0;

void bfs(int n, int m)
{
    int check[8][8]={0};
    int copyLab[8][8]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            copyLab[i][j]=lab[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        int x=wallMake[i][0];
        int y=wallMake[i][1];
        copyLab[x][y]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(lab[i][j]!=2 || check[i][j]!=0)
            {
                continue;
            }
            queue<pair<int,int>> q;
            q.push({i,j});
            check[i][j]=1;
            while(!q.empty())
            {
                int x,y;
                x=q.front().first;
                y=q.front().second;
                q.pop();
                if(x-1>=0 && check[x-1][y]==0 && copyLab[x-1][y]!=1)
                {
                    q.push({x-1,y});
                    check[x-1][y]=1;
                    copyLab[x-1][y]=2;
                }
                if(y-1>=0 && check[x][y-1]==0 && copyLab[x][y-1]!=1)
                {
                    q.push({x,y-1});
                    check[x][y-1]=1;
                    copyLab[x][y-1]=2;
                }
                if(x+1<n && check[x+1][y]==0 && copyLab[x+1][y]!=1)
                {
                    q.push({x+1,y});
                    check[x+1][y]=1;
                    copyLab[x+1][y]=2;
                }
                if(y+1<m && check[x][y+1]==0 && copyLab[x][y+1]!=1)
                {
                    q.push({x,y+1});
                    check[x][y+1]=1;
                    copyLab[x][y+1]=2;
                }
            }
        }
    }
    int space=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(copyLab[i][j]==0)
            {
                space++;
            }
        }
    }
    if(space>maxSpace)
    {
        maxSpace=space;
    }
}

void btf(int n, int m, int countN, int countM, int count)
{
    if(count==3)
    {
        bfs(n,m);
        return;
    }
    for(int i=countN;i<n;i++)
    {
        for(int j=countM;j<m;j++)
        {
            countM=0;
            if(lab[i][j]!=0)
            {
                continue;
            }
            wallMake[count][0]=i;
            wallMake[count][1]=j;
            btf(n, m, i+(j+1)/m, (j+1)%m, count+1);
            wallMake[count][0]=0;
            wallMake[count][1]=0;
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
            cin>>lab[i][j];
        }
    }

    btf(n,m,0,0,0);
    cout<<maxSpace;
}

