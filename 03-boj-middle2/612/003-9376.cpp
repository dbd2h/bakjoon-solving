#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int isOpen=0;

bool des(vector<pair<int,int>> v1, vector<pair<int,int>> v2)
{
    if(v1.size()<v2.size()) return true;
    else return false;
}

void breakWall(int h, int w, int x, int y, char arr[102][102], int check[102][102], int o, int x1, int y1, int x2, int y2)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},1});
    while(!q.empty())
    {
        x=q.front().first.first;
        y=q.front().first.second;
        int c=q.front().second;
        q.pop();
        if(check[x][y]!=c) continue;
        for(int i=0;i<4;i++)
        {
            
            int xp,yp;
            xp=cross[i][0];
            yp=cross[i][1];
            int cx=x+xp;
            int cy=y+yp;
            if(cx<0 || cx>=h+2 || cy<0 || cy>=w+2)
            {
                continue;
            }
            if(arr[cx][cy]=='*') continue;
            if(arr[cx][cy]=='.' && (check[cx][cy]>c || check[cx][cy]==0))
            {
                check[cx][cy]=c;
                q.push({{cx,cy},c});
            }
            if(arr[cx][cy]=='#' && (check[cx][cy]>c+1 || check[cx][cy]==0))
            {
                check[cx][cy]=c+1;
                q.push({{cx,cy},c+1});
            }
        }
    }
    if(o==3 && check[x1][y1]==1 && check[x2][y2]==1) isOpen=1;
}

void prisonBreak()
{
    int h,w;
    cin>>h>>w;
    int x1,y1,x2,y2;
    x1=-1;
    char arr[102][102];
    int a=10000;
    for(int i=0;i<h+2;i++)
    {
        string s;
        if(i!=0 && i!=h+1) cin>>s;
        for(int j=0;j<w+2;j++)
        {
            if(i==0 || i==h+1)
            {
                arr[i][j]='.';
                continue;
            } 
            if(j==0 || j==w+1)
            {
                arr[i][j]='.';
                continue;
            } 
            arr[i][j]=s[j-1];
            if(s[j-1]=='$')
            {   
                arr[i][j]='.';
                if(x1==-1)
                {
                    x1=i;
                    y1=j;
                }
                else
                {
                    x2=i;
                    y2=j;
                }
            }
        }
        
    }
    isOpen=0;
    int check1[102][102]={0};
    int check2[102][102]={0};
    int check3[102][102]={0};
    check1[x1][y1]=1;
    check2[x2][y2]=1;
    check3[0][0]=1;
    
    breakWall(h,w,x1,y1,arr,check1,1, x1, y1, x2, y2);
    breakWall(h,w,x2,y2,arr,check2,2, x1, y1, x2, y2);
    breakWall(h,w,0,0,arr,check3,3, x1, y1, x2, y2);
    if(isOpen)
    {
        cout<<0<<"\n";
        return;
    }
    int minV=100000;
    for(int i=1;i<h+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(arr[i][j]!='#') continue;
            if(minV>check1[i][j]+check2[i][j]+check3[i][j]) minV=check1[i][j]+check2[i][j]+check3[i][j];
        }
    }
    cout<<minV-5<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        prisonBreak();
    }
}