#include <iostream>
#include <queue>

using namespace std;

int combArr[10]={0};
int virus[10][2]={0};

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int minV=-1;

void bfs(int n, int m, int vc, int lab[50][50], int tot)
{
    int check[50][50]={0};
    queue<pair<pair<int,int>,int>> q;
    int sumV=0;
    for(int i=0;i<vc;i++)
    {
        if(combArr[i]==1)
        {
            int x=virus[i][0];
            int y=virus[i][1];
            q.push({{x,y},0});
            check[x][y]=1;
            sumV++;
        }
    }
    int v=0;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second;
        v=c;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
            if(lab[xp][yp]==1 || check[xp][yp]==1) continue;
            check[xp][yp]=1;
            q.push({{xp,yp},c+1});
            sumV++;
        }
    }
    if(sumV!=tot) return;
    if(minV==-1 || minV>v) minV=v;
}

void comb(int vc, int m, int c, int s, int lab[50][50], int tot, int n)
{
    if(s==m)
    {
        bfs(n,m,vc,lab,tot);
        return;
    }
    if(c==vc)
    {
        return;
    }   
    comb(vc,m,c+1,s,lab,tot,n);
    combArr[c]=1;
    comb(vc,m,c+1,s+1,lab,tot,n);
    combArr[c]=0;
}

int main()
{
    int vc=0;
    int n,m;
    cin>>n>>m;
    int lab[50][50]={0};
    int tot=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>lab[i][j];
            if(lab[i][j]==2)
            {
                lab[i][j]=0;
                virus[vc][0]=i;
                virus[vc][1]=j;
                vc++;
            }
            if(lab[i][j]==0) tot++;
        }
    }
    comb(vc,m,0,0,lab,tot,n);
    cout<<minV;
}