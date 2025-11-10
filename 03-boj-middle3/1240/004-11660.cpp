#include <iostream>

#define LEN 1025

using namespace std;

void makeFenwickTreeRow(int n, int map[][LEN], int fenwickTree[][LEN], int i, int idx)
{
    int num=map[i][idx];
    while(idx<=n)
    {
        fenwickTree[i][idx]+=num;
        idx+=(idx & -idx);
    }
}

void makeFenwickTreeColumn(int n, int fenwickTree[][LEN], int idx, int j)
{
    int num=fenwickTree[idx][j];
    idx+=(idx & -idx);
    while(idx<=n)
    {
        fenwickTree[idx][j]+=num;
        idx+=(idx & -idx);
    }
}

int fenwickTreeResult(int x, int y, int fenwickTree[][LEN])
{
    int xidx=x;
    int res=0;
    while(xidx)
    {
        int yidx=y;
        while(yidx)
        {
            res+=fenwickTree[xidx][yidx];
            yidx-=(yidx & -yidx);
        }
        xidx-=(xidx & -xidx);
    }
    return res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int map[LEN][LEN];
    int fenwickTree[LEN][LEN]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>map[i][j];
            makeFenwickTreeRow(n,map,fenwickTree,i,j);
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            makeFenwickTreeColumn(n,fenwickTree,i,j);
        }
    }
    for(int i=0;i<m;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int res=0;
        res+=fenwickTreeResult(x2,y2,fenwickTree);
        res-=fenwickTreeResult(x1-1,y2,fenwickTree);
        res-=fenwickTreeResult(x2,y1-1,fenwickTree);
        res+=fenwickTreeResult(x1-1,y1-1,fenwickTree);
        cout<<res<<"\n";
    }


}