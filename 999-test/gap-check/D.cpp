#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
typedef long long ll;
typedef long double lld;
#define LEN 301
#define INF (int)(1e9)

using namespace std;

int cross[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int diag[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
int main()
{
    int n;
    cin>>n;
    bool arr[LEN][LEN];
    int check[LEN][LEN][4];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            for(int k=0;k<4;k++) check[i][j][k]=INF;
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q; // x,y count,diagCount
    q.push({{0,0},{0,3}});
    for(int i=3;i>=0;i--) check[0][0][i]=0;
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second.first;
        int d=q.front().second.second;
        q.pop();
        if(x==n-1 && y==n-1) continue;
        if(check[x][y][d]<c) continue;
        for(int i=0;i<4;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
            if(arr[xp][yp]==1) continue;
            if(check[xp][yp][d]<=c+1) continue;
            q.push({{xp,yp},{c+1,d}});
            for(int j=d;j>=0;j--) check[xp][yp][j]=min(check[xp][yp][j],c+1);
        }
        if(d>0)
        {
            for(int i=0;i<4;i++)
            {
                int xp=x+diag[i][0];
                int yp=y+diag[i][1];
                if(xp<0 || xp>=n || yp<0 || yp>=n) continue;
                if(arr[xp][yp]==1) continue;
                if(check[xp][yp][d-1]<=c+1) continue;
                q.push({{xp,yp},{c+1,d-1}});
                for(int j=d-1;j>=0;j--) check[xp][yp][j]=min(check[xp][yp][j],c+1);
            }
        }
    }
    int res=INF;
    for(int i=0;i<4;i++)
    {
        res=min(check[n-1][n-1][i],res);
    }
    if(res==INF) res=-1;
    cout<<res;
}