#include <iostream>
#include <string>
#include <queue>

using namespace std;

char arr[50][50];
int check[50][50][4]={0}; // 아,오,위,왼

int cross[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    int n;
    cin>>n;
    int sx,sy,fx,fy;
    sx=-1;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            arr[i][j]=s[j];
            if(s[j]=='#')
            {
                if(sx==-1)
                {
                    sx=i;
                    sy=j;
                }
                else
                {
                    fx=i;
                    fy=j;
                }
            }
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{sx,sy},{1,0}});
    q.push({{sx,sy},{1,1}});
    q.push({{sx,sy},{1,2}});
    q.push({{sx,sy},{1,3}});
    check[sx][sy][0]=1;
    check[sx][sy][1]=1;
    check[sx][sy][2]=1;
    check[sx][sy][3]=1;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second.first;
        int d=q.front().second.second;
        q.pop();
        if(check[x][y][d]<c) continue;
        
        int xp=x+cross[d][0];
        int yp=y+cross[d][1];
        if(!(xp<0 || xp>=n || yp<0 || yp>=n) && !(arr[xp][yp]=='*'))
        {
            if(check[xp][yp][d]>c || check[xp][yp][d]==0)
            {
                check[xp][yp][d]=c;
                q.push({{xp,yp},{c,d}});
            } 
        }
        
        if(arr[x][y]=='!')
        {
            for(int i=-1;i<=1;i+=2)
            {
                xp=x+cross[(d+i+4)%4][0];
                yp=y+cross[(d+i+4)%4][1];
                if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                if(arr[xp][yp]=='*') continue;
                if(check[xp][yp][(d+i+4)%4]>c+1 || check[xp][yp][(d+i+4)%4]==0)
                {
                    check[xp][yp][(d+i+4)%4]=c+1;
                    q.push({{xp,yp},{c+1,(d+i+4)%4}});
                }
            }
        }
    }
    int minV=0;
    for(int i=0;i<4;i++)
    {
        if(check[fx][fy][i]!=0)
        {
            if(minV==0 || check[fx][fy][i]<minV) minV=check[fx][fy][i];
        } 
    }
    cout<<minV-1;
}