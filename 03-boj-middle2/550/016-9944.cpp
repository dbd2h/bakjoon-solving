#include<iostream>
#include <string>

using namespace std;

int cross[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int board[30][30]={0};

void dfs(int n, int m, int ob, int c, int tot, int x, int y, int *minV)
{
    if(n*m-ob-tot==1)
    {
        if(*minV>c) *minV=c;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int xp,yp;
        xp=cross[i][0];
        yp=cross[i][1];
        int cx,cy;
        cx=x;
        cy=y;
        while(true)
        {
            cx+=xp;
            cy+=yp;
            if(cx<0 || cx>=n || cy<0 || cy>=m)
            {
                cx-=xp;
                cy-=yp;
                break;
            }
            if(board[cx][cy]==1)
            {
                cx-=xp;
                cy-=yp;
                break;
            }
        }
        if(cx==x && cy==y)
        {
            continue;
        }
        if(cx==x)
        {
            int count=0;
            for(int j=y;j!=cy;j+=yp)
            {
                board[x][j]=1;
                count++;
            }
            dfs(n,m,ob,c+1,tot+count,x,cy,minV);
            for(int j=y;j!=cy;j+=yp)
            {
                board[x][j]=0;
            }
        }
        else if(cy==y)
        {
            int count=0;
            for(int j=x;j!=cx;j+=xp)
            {
                board[j][y]=1;
                count++;
            }
            dfs(n,m,ob,c+1,tot+count,cx,y,minV);
            for(int j=x;j!=cx;j+=xp)
            {
                board[j][y]=0;
            }
        }
    }
}

int main()
{
    int n,m;
    int count=1;
    while(1)
    {
        for(int i=0;i<30;i++)
        {
            for(int j=0;j<30;j++)
            {
                board[i][j]=0;
            }
        }
        cin>>n>>m;
        if(cin.eof()) break;
        int ob=0;
        int res=10000000;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='*')
                {
                    board[i][j]=1;
                    ob++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==1) continue;
                dfs(n,m,ob,0,0,i,j,&res);
            }
        }
        if(res==10000000) res=-1;
        cout<<"Case "<<count<<": "<<res<<"\n";
        count++;
    }
}