#include <iostream>

using namespace std;

int chess[10][10]={0};

void brute(int n, int c, int *maxN, int isW, int mul)
{
    for(int i=0;i<n;i++)
    {
        for(int j=(i+isW)%2;j<n;j+=2)
        {
            if(i*n+j<mul) continue;
            if(chess[i][j]==0) continue;
            int block[16][2]={0};
            int blockN=0;
            for(int k=0;k<n;k++)
            {
                if(j-i+k<0 || j-i+k>=n) continue;
                if(chess[k][j-i+k]==0) continue;
                chess[k][j-i+k]=0;
                block[blockN][0]=k;
                block[blockN][1]=j-i+k;
                blockN++;
            }
            for(int k=0;k<n;k++)
            {
                if(j+i-k<0 || j+i-k>=n) continue;
                if(chess[k][j+i-k]==0) continue;
                chess[k][j+i-k]=0;
                block[blockN][0]=k;
                block[blockN][1]=j+i-k;
                blockN++;
            }
            brute(n,c+1,maxN,isW,i*n+j);
            for(int k=0;k<blockN;k++)
            {
                chess[block[k][0]][block[k][1]]=1;
            }
        }
    }
    if(*maxN<c) *maxN=c;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>chess[i][j];
        }
    }
    int resultB=0;
    int resultW=0;
    brute(n,0,&resultB,0,0);
    brute(n,0,&resultW,1,0);
    cout<<resultB+resultW;
}