#include <iostream>
#include <queue>

#define MAX_LEN 102

using namespace std;

void bfs(int (*land)[MAX_LEN], int l, int x, int y, int count)
{
    queue<pair<int, int>> q;
    q.push({x,y});
    land[x][y]=count;
    pair<int,int> a;
    int x1,y1;
    while(!q.empty())
    {
        a=q.front();
        x1=a.first;
        y1=a.second;
        q.pop();
        for(int i=-1;i<=1;i+=2)
        {
            if(land[x1][y1+i]==1)
            {
                land[x1][y1+i]=count;
                q.push({x1, y1+i});
            }
            if(land[x1+i][y1]==1)
            {
                land[x1+i][y1]=count;
                q.push({x1+i, y1});
            }
        }
    }

}

int isEdge(int (*land)[MAX_LEN], int x, int y)
{
    for(int i=-1;i<=1;i+=2)
    {
        if(land[x][y+i]==0)
        {
            return 1;
        }
        if(land[x+i][y]==0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int land[MAX_LEN][MAX_LEN];
    for(int i=0;i<MAX_LEN;i++)
    {
        for(int j=0;j<MAX_LEN;j++)
        {
            land[i][j]=-1;
        }
    }
    int l;
    cin>>l;
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=l;j++)
        {
            cin>>land[i][j];
        }
    }
    int count=2;
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(land[i][j]==1)
            {
                bfs(land, l, i, j, count);
                count++;
            }
        }
    }
    
    int cur;
    int min=MAX_LEN*3;
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(min==0)
            {
                break;
            }
            if(isEdge(land, i, j) && land[i][j]!=0)
            {
                int landCount[MAX_LEN][MAX_LEN]={0};
                queue<pair<int, int>> q;
                q.push({i, j});
                int x,y;
                pair<int, int> a;
                cur=land[i][j];
                int finish=0;
                while(!q.empty())
                {
                    a=q.front();
                    x=a.first;
                    y=a.second;
                    q.pop();
                    for(int c=-1;c<=1;c+=2)
                    {
                        if(land[x][y+c]>0 && land[x][y+c]!=cur)
                        {
                            if(min>landCount[x][y])
                            {
                                min=landCount[x][y];
                                finish=1;
                            }
                            break;
                        }
                        if(land[x+c][y]>0 && land[x+c][y]!=cur)
                        {
                            if(min>landCount[x][y])
                            {
                                min=landCount[x][y];
                                finish=1;
                            }
                            break;
                        }
                        if(land[x][y+c]==0 && landCount[x][y+c]==0)
                        {
                            landCount[x][y+c]=landCount[x][y]+1;
                            q.push({x, y+c});
                        }
                        if(land[x+c][y]==0 && landCount[x+c][y]==0)
                        {
                            landCount[x+c][y]=landCount[x][y]+1;
                            q.push({x+c, y});
                        }
                    }                    
                    if(min<=landCount[x][y])
                    {
                        finish=1;
                    }
                    if(finish)
                    {
                        break;
                    }

                }
            }
        }
    }
    cout<<min;
}