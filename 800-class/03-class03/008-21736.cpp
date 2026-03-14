#include <iostream>
#include <string>
#include <queue>

using namespace std;

int cross[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[600][600];
    pair<int,int> doYeon;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='O')
            {
                arr[i][j]=1;
            }
            else if(s[j]=='X')
            {
                arr[i][j]=0;
            }
            else if(s[j]=='P')
            {
                arr[i][j]=2;
            }
            else if(s[j]=='I')
            {
                arr[i][j]=1;
                doYeon={i,j};
            }
        }
    }
    int res=0;
    queue<pair<int,int>> q;
    q.push(doYeon);
    bool check[600][600]={0};
    check[doYeon.first][doYeon.second]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xp=x+cross[i][0];
            int yp=y+cross[i][1];
            if(xp<0 || xp>=n || yp<0 || yp>=m) continue;
            if(check[xp][yp]) continue;
            if(arr[xp][yp]==0) continue;
            if(arr[xp][yp]==2) res++;
            check[xp][yp]=1;
            q.push({xp,yp});
        }
    }
    if(res==0) cout<<"TT";
    else cout<<res;
}