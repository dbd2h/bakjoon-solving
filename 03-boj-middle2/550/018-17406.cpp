#include <iostream>

using namespace std;

int arr[50][50]={0};
int spin[6][3]={0};
int bit[6]={0};
int ord[6]={0};
int minV=10000000;

void spinArr(int carr[][50], int index)
{
    int r,c,s;
    r=spin[index][0];
    c=spin[index][1];
    s=spin[index][2];
    for(int i=1;i<=s;i++)
    {
        int num=carr[r-i][c-i];
        for(int j=0;j<2*i;j++)
        {
            carr[r-i+j][c-i]=carr[r-i+j+1][c-i];
        }
        for(int j=0;j<2*i;j++)
        {
            carr[r+i][c-i+j]=carr[r+i][c-i+j+1];
        }
        for(int j=0;j<2*i;j++)
        {
            carr[r+i-j][c+i]=carr[r+i-j-1][c+i];
        }
        for(int j=0;j<2*i;j++)
        {
            carr[r-i][c+i-j]=carr[r-i][c+i-j-1];
            if(j==2*i-1)
            {
                carr[r-i][c+i-j]=num;
            }
        }
    }
}

void perm(int n, int m, int k, int c)
{
    if(c==6)
    {
        int copyArr[50][50]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                copyArr[i][j]=arr[i][j];
            }
        }
        for(int i=0;i<6;i++)
        {
            spinArr(copyArr,ord[i]);
        }
        for(int i=0;i<n;i++)
        {
            int sumV=0;
            for(int j=0;j<m;j++)
            {
                sumV+=copyArr[i][j];
            }
            if(sumV<minV) minV=sumV;
        }
    }
    for(int i=0;i<6;i++)
    {
        if(bit[i]==1) continue;
        ord[c]=i;
        bit[i]=1;
        perm(n,m,k,c+1);
        ord[c]=0;
        bit[i]=0;
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<k;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        spin[i][0]=a-1;
        spin[i][1]=b-1;
        spin[i][2]=c;
    }
    perm(n,m,k,0);
    cout<<minV;
}