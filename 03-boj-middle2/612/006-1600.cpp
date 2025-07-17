#include <iostream>
#include <queue>

using namespace std;

int arr[200][200]={0};

int check[200][200][31]={0};

int cross[4][2]={{1,0},{0,1},{0,-1},{-1,0}};

int horse[8][2]={{2,1},{1,2},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};

int main()
{
    int k,w,h;
    cin>>k>>w>>h;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>arr[i][j];
        }
    }
    if(h==1 && w==1)
    {
        cout<<0;
        return 0;
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{k,1}});
    check[0][0][k]=1;
    while(!q.empty())
    {
        int x,y,n,c;
        x=q.front().first.first;
        y=q.front().first.second;
        n=q.front().second.first;
        c=q.front().second.second;
        q.pop();
        if(check[x][y][n]<c) continue;
        for(int i=0;i<4;i++)
        {
            int xp,yp;
            xp=x+cross[i][0];
            yp=y+cross[i][1];
            if(xp<0 || xp>=h || yp<0 || yp>=w) continue;
            if(arr[xp][yp]==1) continue;
            if(check[xp][yp][n]!=0 && check[xp][yp][n]<=c+1) continue;
            q.push({{xp,yp},{n,c+1}});
            check[xp][yp][n]=c+1;
            for(int j=n-1;j>=0;j--)
            {
                if(check[xp][yp][j]!=0 && check[xp][yp][j]<=c+1) break;
                check[xp][yp][j]=c+1;
            }
        }
        for(int i=0;i<8;i++)
        {
            if(n==0) break;
            int xp,yp;
            xp=x+horse[i][0];
            yp=y+horse[i][1];
            
            if(xp<0 || xp>=h || yp<0 || yp>=w) continue;
            if(arr[xp][yp]==1) continue;
            if(check[xp][yp][n-1]!=0 && check[xp][yp][n-1]<=c+1) continue;
            q.push({{xp,yp},{n-1,c+1}});
            check[xp][yp][n-1]=c+1;
            for(int j=n-2;j>=0;j--)
            {
                if(check[xp][yp][j]!=0 && check[xp][yp][j]<=c+1) break;
                check[xp][yp][j]=c+1;
            }
        }
    }
    cout<<check[h-1][w-1][0]-1;
}