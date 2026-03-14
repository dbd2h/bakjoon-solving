#include <iostream>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void diffuse(int arr[50][50], int r, int c)
{
    int addArr[50][50]={0};
    for(int x=0;x<r;x++)
    {
        for(int y=0;y<c;y++)
        {
            if(arr[x][y]==0 || arr[x][y]==-1) continue;
            int diffuseAmount=arr[x][y]/5;
            for(int i=0;i<4;i++)
            {
                int xp=x+cross[i][0];
                int yp=y+cross[i][1];
                if(xp<0 || xp>=r || yp<0 || yp>=c) continue;
                if(arr[xp][yp]==-1) continue;
                addArr[xp][yp]+=diffuseAmount;
                arr[x][y]-=diffuseAmount;
            }
        }
    }
    for(int x=0;x<r;x++)
    {
        for(int y=0;y<c;y++)
        {
            arr[x][y]+=addArr[x][y];
        }
    }
    return;
}

void cycle(int arr[50][50], int r, int c, int ap)
{
    for(int i=ap-2;i>=0;i--)
    {
        arr[i+1][0]=arr[i][0];
    }
    for(int i=1;i<c;i++)
    {
        arr[0][i-1]=arr[0][i];
    }
    for(int i=1;i<=ap;i++)
    {
        arr[i-1][c-1]=arr[i][c-1];
    }
    for(int i=c-2;i>=1;i--)
    {
        arr[ap][i+1]=arr[ap][i];
    }
    arr[ap][1]=0;
    for(int i=ap+3;i<r;i++)
    {
        arr[i-1][0]=arr[i][0];
    }
    for(int i=1;i<c;i++)
    {
        arr[r-1][i-1]=arr[r-1][i];
    }
    for(int i=r-2;i>=ap+1;i--)
    {
        arr[i+1][c-1]=arr[i][c-1];
    }
    for(int i=c-2;i>=1;i--)
    {
        arr[ap+1][i+1]=arr[ap+1][i];
    }
    arr[ap+1][1]=0;
}

int main()
{
    int arr[50][50];
    int r,c,t;
    cin>>r>>c>>t;
    int airPurifier=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==-1 && airPurifier==0) airPurifier=i;
        }
    }
    for(int i=0;i<t;i++)
    {
        diffuse(arr,r,c);
        cycle(arr,r,c,airPurifier);
    }
    int res=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==-1) continue;
            res+=arr[i][j];
        }
    }
    cout<<res;
}