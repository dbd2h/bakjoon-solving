#include <iostream>
#include <string>

using namespace std;

char arr[15][15];
int cross[15][15]={0};
int crossN[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int abs(int n)
{
    if(n<0) n=-n;
    return n;
}

int crossCheck(int x1, int y1, int x2, int y2, int n1, int n2)
{
    int res=0;
    int map1[15][15]={0};
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<4;j++)
        {
            int xp=crossN[j][0]*i;
            int yp=crossN[j][1]*i;
            map1[x1+xp][y1+yp]=1;
        }
        int isF=0;
        for(int j=0;j<=n2;j++)
        {
            for(int k=0;k<4;k++)
            {
                int xp=crossN[k][0]*j;
                int yp=crossN[k][1]*j;
                if(map1[x2+xp][y2+yp]==1)
                {
                    isF=1;
                    if(res<(i*4+1)*(j*4-3)) res=(i*4+1)*(j*4-3);
                    break;
                }
            }
            if(isF) break;
        }
        if(isF==0)
        {
            if(res<(i*4+1)*(n2*4+1)) res=(i*4+1)*(n2*4+1);
        }
    }
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            arr[i][j]=s[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='.') continue;
            int l=1;
            while(true)
            {
                if(i-l<0 || j-l<0 || i+l>=n || j+l>=m) break;
                if(arr[i-l][j]=='#' && arr[i+l][j]=='#' && arr[i][j-l]=='#' && arr[i][j+l]=='#') l++;
                else break;
            }
            cross[i][j]=l-1;
        }
    }
    int maxV=0;
    for(int i=0;i<n*m;i++)
    {
        int x1=i/m;
        int y1=i%m;
        if(arr[x1][y1]=='.') continue;
        int n1=cross[x1][y1];
        for(int j=i+1;j<n*m;j++)
        {
            int x2=j/m;
            int y2=j%m;
            if(arr[x2][y2]=='.') continue;
            int n2=cross[x2][y2];
            if(maxV>=(n1*4+1)*(n2*4+1)) continue;
            int res=crossCheck(x1,y1,x2,y2,n1,n2);
            if(res>maxV) maxV=res;
        }
    }
    cout<<maxV;
}