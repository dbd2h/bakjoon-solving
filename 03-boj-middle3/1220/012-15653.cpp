#include <iostream>
#include <string>
#include <queue>

using namespace std;

int cross[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int n,m;
    cin>>n>>m;
    pair<int,int> R,B;
    int map[10][10];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='#')
            {
                map[i][j]=-1;
                continue;
            } 
            map[i][j]=0;
            if(s[j]=='R') R={i,j};
            else if(s[j]=='B') B={i,j};
            else if(s[j]=='O') map[i][j]=1;
        }
    }
    bool check[11][11][11][11]={0};
    queue<pair<pair<pair<int,int>,pair<int,int>>,int>> q;
    q.push({{R,B},0});
    check[R.first][R.second][B.first][B.second]=1;
    int res=-1;
    while(!q.empty())
    {
        int rx=q.front().first.first.first;
        int ry=q.front().first.first.second;
        int bx=q.front().first.second.first;
        int by=q.front().first.second.second;
        int c=q.front().second;
        q.pop();
        bool isF=false;
        bool isB=false;
        for(int i=0;i<4;i++)
        {
            int crx=rx;
            int cry=ry;
            int cbx=bx;
            int cby=by;
            while(true)
            {
                if(map[crx+cross[i][0]][cry+cross[i][1]]==-1 && map[cbx+cross[i][0]][cby+cross[i][1]]==-1)
                {
                    if(isF) break;
                    if(crx==cbx && cry==cby)
                    {
                        
                        if(i==0)
                        {
                            if(rx>bx) cbx--;
                            else crx--;
                        }
                        else if(i==1)
                        {
                            if(rx>bx) crx++;
                            else cbx++;
                        }
                        else if(i==2)
                        {
                            if(ry>by) cby--;
                            else cry--;
                        }
                        else if(i==3)
                        {
                            if(ry>by) cry++;
                            else cby++;
                        }
                    }
                    if(check[crx][cry][cbx][cby]==1) break;
                    q.push({{{crx,cry},{cbx,cby}},c+1});
                    check[crx][cry][cbx][cby]=1;
                    break;
                }
                if(map[crx+cross[i][0]][cry+cross[i][1]]!=-1)
                {
                    crx+=cross[i][0];
                    cry+=cross[i][1];
                }
                if(map[cbx+cross[i][0]][cby+cross[i][1]]!=-1)
                {
                    cbx+=cross[i][0];
                    cby+=cross[i][1];
                }
                if(map[crx][cry]==1)
                {
                    isF=true;
                }
                if(map[cbx][cby]==1)
                {
                    isB=true;
                    isF=true;
                }
                if(isB) break;
            }
            if(isF && !isB)
            {
                res=c+1;
                break;
            }
            if(isB)
            {
                isF=false;
                isB=false;
            }
        }
        if(isF && !isB) break;
    }
    cout<<res;
}