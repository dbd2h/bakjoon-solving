#include <iostream>

using namespace std;

int arr[8][8]={0};
int cctv[8][2]={0};

int cross[5][4][4]={{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},{{1,0,1,0},{0,1,0,1},{0,0,0,0},{0,0,0,0}},{{1,1,0,0},{1,0,0,1},{0,1,1,0},{0,0,1,1}},{{1,1,1,0},{1,1,0,1},{1,0,1,1},{0,1,1,1}},{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};

void brute(int n, int m, int c, int cctvN, int *minN)
{
    if(cctvN==c)
    {
        int num=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==0) num++;
            }
        }
        if(*minN>num) *minN=num;
        return;
    }
    int cctvX,cctvY;
    cctvX=cctv[c][0];
    cctvY=cctv[c][1];
    int cctvW=arr[cctvX][cctvY];
    for(int i=0;i<4;i++)
    {
        int isScan[16][2]={0};
        int scanN=0;
        int cu=cross[cctvW-1][i][0];
        int cr=cross[cctvW-1][i][1];
        int cd=cross[cctvW-1][i][2];
        int cl=cross[cctvW-1][i][3];
        if(cu==0 && cr==0 && cd==0 && cl==0) return;
        if(cu==1)
        {
            int x=cctvX-1;
            while(x>=0 && arr[x][cctvY]!=6)
            {
                if(arr[x][cctvY]==0)
                {
                    isScan[scanN][0]=x;
                    isScan[scanN][1]=cctvY;
                    scanN++;
                    arr[x][cctvY]=-1;
                }
                x--;
            }
        }
        if(cd==1)
        {
            int x=cctvX+1;
            while(x<n && arr[x][cctvY]!=6)
            {
                if(arr[x][cctvY]==0)
                {
                    isScan[scanN][0]=x;
                    isScan[scanN][1]=cctvY;
                    scanN++;
                    arr[x][cctvY]=-1;
                }
                x++;
            }
        }
        if(cl==1)
        {
            int y=cctvY-1;
            while(y>=0 && arr[cctvX][y]!=6)
            {
                if(arr[cctvX][y]==0)
                {
                    isScan[scanN][0]=cctvX;
                    isScan[scanN][1]=y;
                    scanN++;
                    arr[cctvX][y]=-1;
                }
                y--;
            }
        }
        if(cr==1)
        {
            int y=cctvY+1;
            while(y<m && arr[cctvX][y]!=6)
            {
                if(arr[cctvX][y]==0)
                {
                    isScan[scanN][0]=cctvX;
                    isScan[scanN][1]=y;
                    scanN++;
                    arr[cctvX][y]=-1;
                }
                y++;
            }
        }
        brute(n,m,c+1,cctvN, minN);
        for(int j=0;j<scanN;j++)
        {
            arr[isScan[j][0]][isScan[j][1]]=0;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int cctvN=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!=0 && arr[i][j]!=6)
            {
                cctv[cctvN][0]=i;
                cctv[cctvN][1]=j;
                cctvN++;
            }
        }
    }
    int result=64;
    if(cctvN==0)
    {
        result=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==0) result++;
            }
        }
        cout<<result;
        return 0;
    }
    brute(n,m,0,cctvN,&result);
    cout<<result;
}