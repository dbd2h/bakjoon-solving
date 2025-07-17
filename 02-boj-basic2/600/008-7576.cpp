#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tomato[1002][1002]={0};
    int check[1002][1002]={0};
    int m,n;
    cin>>m>>n;
    queue<pair<int,int>> q;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            if(i==0||i==n+1||j==0||j==m+1)
            {
                tomato[i][j]=-1;
            }
            else
            {
                int value;
                cin>>value;
                tomato[i][j]=value;
                if(value==1)
                {
                    check[i][j]=value;
                    q.push({i,j});
                }
            }
        }
    }
    int max=1;
    while(!q.empty())
    {
        pair<int,int> a;
        a=q.front();
        int r,c;
        r=a.first;
        c=a.second;
        q.pop();
        for(int i=-1;i<=1;i++)
        {
            if(tomato[r+i][c]==0&&check[r+i][c]==0)
            {
                q.push({r+i,c});
                check[r+i][c]=check[r][c]+1;
                if(max<check[r+i][c])
                {
                    max=check[r+i][c];
                }
            }
            if(tomato[r][c+i]==0&&check[r][c+i]==0)
            {
                q.push({r,c+i});
                check[r][c+i]=check[r][c]+1;
                if(max<check[r][c+i])
                {
                    max=check[r][c+i];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(check[i][j]==0&&tomato[i][j]!=-1)
            {
                max=0;
                break;
            }
            if(max==0)
            {
                break;
            }
        }
    }
    cout<<max-1;
}