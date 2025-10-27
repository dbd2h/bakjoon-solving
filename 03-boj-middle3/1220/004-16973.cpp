#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    bool arr[1001][1001];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int h,w,sr,sc,fr,fc;
    cin>>h>>w>>sr>>sc>>fr>>fc;
    bool check[1001][1001]={0};
    queue<pair<pair<int,int>,int>> q;
    q.push({{sr,sc},0});
    check[sr][sc]=1;
    int res=-1;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second;
        if(x==fr && y==fc)
        {
            res=c;
            break;
        }
        q.pop();
        // down
        if(x+h<=n && check[x+1][y]==0)
        {
            check[x+1][y]=1;
            int isB=false;
            for(int i=0;i<w;i++)
            {
                if(arr[x+h][y+i]==1)
                {
                    isB=true;
                    break;
                }
            }
            if(!isB)
            {
                q.push({{x+1,y},c+1});
            }
        }

        // right
        if(y+w<=m && check[x][y+1]==0)
        {
            check[x][y+1]=1;
            int isB=false;
            for(int i=0;i<h;i++)
            {
                if(arr[x+i][y+w]==1)
                {
                    isB=true;
                    break;
                }
            }
            if(!isB)
            {
                q.push({{x,y+1},c+1});
            }
        }

        // left
        if(y-1>=1 && check[x][y-1]==0)
        {
            check[x][y-1]=1;
            int isB=false;
            for(int i=0;i<h;i++)
            {
                if(arr[x+i][y-1]==1)
                {
                    isB=true;
                    break;
                }
            }
            if(!isB)
            {
                q.push({{x,y-1},c+1});
            }
        }

        // up
        if(x-1>=1 && check[x-1][y]==0)
        {
            check[x-1][y]=1;
            int isB=false;
            for(int i=0;i<w;i++)
            {
                if(arr[x-1][y+i]==1)
                {
                    isB=true;
                    break;
                }
            }
            if(!isB)
            {
                q.push({{x-1,y},c+1});
            }
        }
    }
    cout<<res;
}