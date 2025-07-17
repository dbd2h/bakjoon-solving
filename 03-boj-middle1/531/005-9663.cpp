#include <iostream>

#define MAX_LEN 15

using namespace std;

int chess[MAX_LEN][MAX_LEN]={0};

int isQueen(int x, int y, int n)
{
    for(int i=x-1;i>=0;i--)
    {
        if(chess[i][y]==1)
        {
            return 0;
        }
    }
    for(int i=1;i<=x;i++)
    {
        if(x-i<0 || y-i<0)
        {
            break;
        }
        if(chess[x-i][y-i]==1)
        {
            return 0;
        }
    }
    for(int i=1;i<=x;i++)
    {
        if(x-i<0 || y+i>=n)
        {
            break;
        }
        if(chess[x-i][y+i]==1)
        {
            return 0;
        }
    }
    return 1;
}

void NQueen(int n, int cur, int *batch)
{
    if(n==cur)
    {
        (*batch)++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isQueen(cur,i,n)==0)
        {
            continue;
        }
        chess[cur][i]=1;
        NQueen(n, cur+1, batch);
        chess[cur][i]=0;
    }
}

int main()
{
    int batch=0;
    int n;
    cin>>n;
    NQueen(n,0,&batch);
    cout<<batch;
}